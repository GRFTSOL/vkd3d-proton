# For maintainers: remember to update vcs_tag(fallback) as well
project('vkd3d-proton', ['c', 'cpp'], version : '2.14.1', meson_version : '>= 0.49', default_options : [
  'warning_level=2', 'c_std=c11', 'cpp_std=c++17'
])

cpu_family = target_machine.cpu_family()

vkd3d_compiler = meson.get_compiler('c')
vkd3d_is_msvc  = vkd3d_compiler.get_id() == 'msvc' or vkd3d_compiler.get_id() == 'clang-cl'
vkd3d_is_clang = vkd3d_compiler.get_id() == 'clang' or vkd3d_compiler.get_id() == 'clang-cl'
vkd3d_platform = target_machine.system()

vkd3d_buildtype = get_option('buildtype')
vkd3d_debug     = vkd3d_buildtype == 'debug' or vkd3d_buildtype == 'debugoptimized'

enable_tests             = get_option('enable_tests')
enable_extras            = get_option('enable_extras')
enable_profiling         = get_option('enable_profiling')
enable_renderdoc         = get_option('enable_renderdoc')
enable_descriptor_qa     = get_option('enable_descriptor_qa')
enable_trace             = get_option('enable_trace')
enable_dxilconv          = get_option('enable_dxilconv')

if enable_trace == 'auto'
  enable_trace = vkd3d_debug
else
  enable_trace = enable_trace == 'true'
endif

add_project_arguments('-D_GNU_SOURCE',   language : 'c')
add_project_arguments('-DPACKAGE_VERSION="' + meson.project_version() + '"',   language : 'c')

if vkd3d_platform == 'windows'
  add_project_arguments('-D_WIN32_WINNT=0x600', language : 'c')
endif

if enable_profiling
  add_project_arguments('-DVKD3D_ENABLE_PROFILING', language : 'c')
endif

if enable_renderdoc
  add_project_arguments('-DVKD3D_ENABLE_RENDERDOC', language : 'c')
endif

if enable_descriptor_qa
  add_project_arguments('-DVKD3D_ENABLE_DESCRIPTOR_QA', language : 'c')
endif

if not enable_trace
  add_project_arguments('-DVKD3D_NO_TRACE_MESSAGES', language : 'c')
endif

enable_breadcrumbs = enable_trace
if enable_breadcrumbs
  add_project_arguments('-DVKD3D_ENABLE_BREADCRUMBS', language : 'c')
endif

if enable_dxilconv and vkd3d_platform == 'windows'
  add_project_arguments('-DVKD3D_ENABLE_DXILCONV', language : 'c')
endif

vkd3d_external_includes = [ './khronos/Vulkan-Headers/include', './khronos/SPIRV-Headers/include' ]
vkd3d_public_includes   = [ './include' ] + vkd3d_external_includes
vkd3d_private_includes  = [ './include/private' ] + vkd3d_public_includes

vkd3d_external_includes = include_directories(vkd3d_external_includes)
vkd3d_public_includes   = include_directories(vkd3d_public_includes)
vkd3d_private_includes  = include_directories(vkd3d_private_includes)

vkd3d_shader_private_includes = [ './libs/vkd3d-shader' ]
vkd3d_shader_private_includes = include_directories(vkd3d_shader_private_includes)

idl_compiler  = find_program('widl', required : false)
# widl-stable is used on Debian. If cross-file defines widl-mingw-tools-fallback, that will also be attempted.
if not idl_compiler.found()
  idl_compiler  = find_program('widl-stable', 'widl-mingw-tools-fallback')
endif

idl_generator = generator(idl_compiler,
  output    : [ '@BASENAME@.h' ],
  arguments : [ '-h', '-o', '@OUTPUT@', '@INPUT@' ])

glsl_compiler  = find_program('glslang', 'glslangValidator')
glsl_args = [ '-V', '--target-env', 'vulkan1.3', '--vn', '@BASENAME@', '@INPUT@', '-o', '@OUTPUT@', '--depfile', '@DEPFILE@', '--quiet' ]
glsl_generator = generator(glsl_compiler,
  output    : [ '@BASENAME@.h' ],
  depfile   : '@BASENAME@.h.d',
  arguments : glsl_args)

threads_dep = dependency('threads')

if vkd3d_platform == 'linux'
  lib_dl           = vkd3d_compiler.find_library('dl')
  vkd3d_extra_libs = [ lib_dl, threads_dep ]
elif vkd3d_platform == 'windows'
  lib_dxgi         = vkd3d_compiler.find_library('dxgi')
  vkd3d_extra_libs = [ threads_dep ]
else
  error('Unknown platform')
endif

add_project_arguments(vkd3d_compiler.get_supported_arguments([
    '-fvisibility=hidden',
    '-msse',
    '-msse2',
    # For some reason, the use of VLAs isn't in all+extra+pedantic
    # We don't want to use these accidentally from consts...
    '-Wvla',
    '-Wno-format',
    '-Wno-missing-field-initializers',
    '-Wno-unused-parameter',
    '-Wdeclaration-after-statement',
    '/wd4244', # Narrowing conversion
    '/wd4101', # Unreferenced local variable
    '/wd4267', # Another narrowing conversion
    '/wd4996', # Secure no warnings
    '/wd4334', # Result of 32-bit shift cast to 64-bit
    '/wd4146', # Unary minus on unsigned
    '/wd4305', # Truncation from double to float
    ]),
  language : 'c')

if cpu_family == 'x86'
  add_global_link_arguments(vkd3d_compiler.get_supported_link_arguments([
      '-Wl,--kill-at',
      '-Wl,--enable-stdcall-fixup']),
    language : [ 'c', 'cpp' ])

  # Need to link against libatomic for 64-bit atomic emulation on x86
  # when using clang.
  if vkd3d_platform == 'linux'
    if vkd3d_is_clang
      lib_atomic = vkd3d_compiler.find_library('atomic')
      vkd3d_extra_libs += lib_atomic
    endif
  endif
endif

if not vkd3d_is_msvc
  # We need to set the section alignment for debug symbols to
  # work properly as well as avoiding a memcpy from the Wine loader.
  if vkd3d_compiler.has_link_argument('-Wl,--file-alignment=4096')
    add_global_link_arguments('-Wl,--file-alignment=4096', language : [ 'c', 'cpp' ])
  endif
endif

if vkd3d_platform == 'windows'
  if vkd3d_compiler.has_link_argument('-static')
    add_global_link_arguments('-static', language : [ 'c', 'cpp' ])
  endif
  if vkd3d_compiler.has_link_argument('-static-libgcc')
    add_global_link_arguments('-static-libgcc', language : [ 'c', 'cpp' ])
  endif
  if vkd3d_compiler.has_link_argument('-static-libstdc++')
    add_global_link_arguments('-static-libstdc++', language : [ 'cpp' ])
  endif
  if vkd3d_compiler.has_link_argument('/NOIMPLIB')
    add_global_link_arguments('/NOIMPLIB', language : [ 'c', 'cpp' ])
  endif
  if not vkd3d_is_clang and vkd3d_compiler.has_link_argument('/NOEXP')
    add_global_link_arguments('/NOEXP', language : [ 'c', 'cpp' ])
  endif
endif

vkd3d_build = vcs_tag(
  command : ['git', 'describe', '--always', '--exclude=*', '--abbrev=15', '--dirty=0'],
  input   : 'vkd3d_build.h.in',
  output  : 'vkd3d_build.h', fallback : '12345678')

vkd3d_version = vcs_tag(
  command : ['git', 'describe', '--always', '--tags', '--dirty=+'],
  input   : 'vkd3d_version.h.in',
  output  : 'vkd3d_version.h', fallback : '201401')

dxil_spirv = subproject('dxil-spirv')
dxil_spirv_dep = dxil_spirv.get_variable('dxil_spirv_dep')

subdir('include')
subdir('libs')

if vkd3d_platform == 'windows'
  # MinGW LD on x86 emits incorrect implib with ordinal suffixes.
  # As a workaround, just link to the system D3D12.
  lib_d3d12 = vkd3d_compiler.find_library('d3d12')
else
  lib_d3d12 = d3d12_dep
endif

if vkd3d_platform == 'linux'
  pkg = import('pkgconfig')
  pkg.generate(vkd3d_lib, filebase : 'libvkd3d-proton', subdirs : 'vkd3d-proton', description : 'The vkd3d-proton D3D12 implementation')
  install_headers('include/vkd3d_sonames.h', 'include/vkd3d.h', 'include/vkd3d_types.h', 'include/vkd3d_win32.h', 'include/vkd3d_windows.h', subdir : 'vkd3d-proton')
  # TODO: Figure out how to export the IDL generated headers as well.
endif

if enable_tests
  subdir('tests')
endif

if enable_extras
  if vkd3d_platform == 'linux'
    lib_m            = vkd3d_compiler.find_library('m')
    lib_xcb          = vkd3d_compiler.find_library('xcb')
    lib_xcbkeysyms   = vkd3d_compiler.find_library('xcb-keysyms')
  endif

  subdir('demos')
  subdir('programs')
endif
