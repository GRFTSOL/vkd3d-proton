static const DWORD vs_null_root_signature_code_dxbc[] =
{
    0x43425844, 0x7d259eed, 0xd7246bd4, 0xeb5e0efc, 0x9e31fb00, 0x00000001, 0x000001b4, 0x00000004,
    0x00000030, 0x00000064, 0x00000098, 0x0000017c, 0x4e475349, 0x0000002c, 0x00000001, 0x00000008,
    0x00000020, 0x00000000, 0x00000006, 0x00000001, 0x00000000, 0x00000101, 0x565f5653, 0x45545245,
    0x00444958, 0x4e47534f, 0x0000002c, 0x00000001, 0x00000008, 0x00000020, 0x00000000, 0x00000001,
    0x00000003, 0x00000000, 0x0000000f, 0x505f5653, 0x5449534f, 0x004e4f49, 0x58454853, 0x000000dc,
    0x00010050, 0x00000037, 0x0100086a, 0x04000060, 0x00101012, 0x00000000, 0x00000006, 0x04000067,
    0x001020f2, 0x00000000, 0x00000001, 0x02000068, 0x00000001, 0x0a000001, 0x00100032, 0x00000000,
    0x00101006, 0x00000000, 0x00004002, 0x00000001, 0x00000002, 0x00000000, 0x00000000, 0x05000056,
    0x00100032, 0x00000000, 0x00100046, 0x00000000, 0x09000032, 0x00102012, 0x00000000, 0x0010000a,
    0x00000000, 0x00004001, 0x40800000, 0x00004001, 0xbf800000, 0x09000032, 0x00102022, 0x00000000,
    0x0010001a, 0x00000000, 0x00004001, 0x40000000, 0x00004001, 0xbf800000, 0x08000036, 0x001020c2,
    0x00000000, 0x00004002, 0x00000000, 0x00000000, 0x00000000, 0x3f800000, 0x0100003e, 0x30535452,
    0x00000030, 0x00000002, 0x00000001, 0x00000018, 0x00000000, 0x00000030, 0x00000000, 0x00000001,
    0x00000000, 0x00000024, 0x00000000, 0x00000000, 0x00000004,
};
#ifdef __GNUC__
#define UNUSED_ARRAY_ATTR __attribute__((unused))
#else
#define UNUSED_ARRAY_ATTR
#endif
UNUSED_ARRAY_ATTR static const D3D12_SHADER_BYTECODE vs_null_root_signature_dxbc = { vs_null_root_signature_code_dxbc, sizeof(vs_null_root_signature_code_dxbc) };
#undef UNUSED_ARRAY_ATTR
