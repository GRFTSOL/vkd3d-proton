static const DWORD ps_create_pso_code_dxbc[] =
{
    0x43425844, 0x29b14cf3, 0xb991cf90, 0x9e455ffc, 0x4675b046, 0x00000001, 0x000000b4, 0x00000003,
    0x0000002c, 0x0000003c, 0x00000070, 0x4e475349, 0x00000008, 0x00000000, 0x00000008, 0x4e47534f,
    0x0000002c, 0x00000001, 0x00000008, 0x00000020, 0x00000000, 0x00000000, 0x00000003, 0x00000000,
    0x0000000f, 0x545f5653, 0x45475241, 0xabab0054, 0x58454853, 0x0000003c, 0x00000050, 0x0000000f,
    0x0100086a, 0x03000065, 0x001020f2, 0x00000000, 0x08000036, 0x001020f2, 0x00000000, 0x00004002,
    0x3f800000, 0x3f800000, 0x3f800000, 0x3f800000, 0x0100003e,
};
#ifdef __GNUC__
#define UNUSED_ARRAY_ATTR __attribute__((unused))
#else
#define UNUSED_ARRAY_ATTR
#endif
UNUSED_ARRAY_ATTR static const D3D12_SHADER_BYTECODE ps_create_pso_dxbc = { ps_create_pso_code_dxbc, sizeof(ps_create_pso_code_dxbc) };
#undef UNUSED_ARRAY_ATTR
