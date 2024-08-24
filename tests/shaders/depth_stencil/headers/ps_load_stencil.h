static const DWORD ps_load_stencil_code_dxbc[] =
{
    0x43425844, 0x9ad18dbc, 0x98de0e54, 0xe3c15d5b, 0xac8b580a, 0x00000001, 0x00000138, 0x00000003,
    0x0000002c, 0x00000060, 0x00000094, 0x4e475349, 0x0000002c, 0x00000001, 0x00000008, 0x00000020,
    0x00000000, 0x00000001, 0x00000003, 0x00000000, 0x0000030f, 0x505f5653, 0x7469736f, 0x006e6f69,
    0x4e47534f, 0x0000002c, 0x00000001, 0x00000008, 0x00000020, 0x00000000, 0x00000000, 0x00000001,
    0x00000000, 0x0000000f, 0x545f5653, 0x65677261, 0xabab0074, 0x58454853, 0x0000009c, 0x00000050,
    0x00000027, 0x0100086a, 0x04001858, 0x00107000, 0x00000000, 0x00004444, 0x04002064, 0x00101032,
    0x00000000, 0x00000001, 0x03000065, 0x001020f2, 0x00000000, 0x02000068, 0x00000001, 0x0500001b,
    0x00100032, 0x00000000, 0x00101046, 0x00000000, 0x08000036, 0x001000c2, 0x00000000, 0x00004002,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x8900002d, 0x800000c2, 0x00111103, 0x001020f2,
    0x00000000, 0x00100e46, 0x00000000, 0x00107e46, 0x00000000, 0x0100003e,
};
#ifdef __GNUC__
#define UNUSED_ARRAY_ATTR __attribute__((unused))
#else
#define UNUSED_ARRAY_ATTR
#endif
UNUSED_ARRAY_ATTR static const D3D12_SHADER_BYTECODE ps_load_stencil_dxbc = { ps_load_stencil_code_dxbc, sizeof(ps_load_stencil_code_dxbc) };
#undef UNUSED_ARRAY_ATTR