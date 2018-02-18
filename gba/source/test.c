
//{{BLOCK(test)

//======================================================================
//
//	test, 32x32@4, 
//	+ palette 256 entries, not compressed
//	+ 16 tiles not compressed
//	Total size: 512 + 512 = 1024
//
//	Time-stamp: 2018-02-15, 00:28:12
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.13
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

const unsigned short testTiles[256] __attribute__((aligned(4))) __attribute__((visibility("hidden")))=
{
	0x0000,0x0000,0x1110,0x0221,0x2210,0x0212,0x2210,0x0212,
	0x2210,0x0212,0x2210,0x0212,0x2210,0x0212,0x1100,0x0011,
	0x0000,0x0000,0x2220,0x0212,0x2220,0x0212,0x2220,0x0212,
	0x2220,0x0212,0x2220,0x0212,0x2220,0x0212,0x0000,0x0010,
	0x0000,0x0000,0x2220,0x0222,0x1120,0x0211,0x2220,0x0212,
	0x2220,0x0221,0x1120,0x0222,0x1120,0x0111,0x0000,0x0000,
	0x0000,0x0000,0x1120,0x0211,0x2220,0x0212,0x1220,0x0211,
	0x2220,0x0212,0x1120,0x0211,0x2220,0x0222,0x0000,0x0000,

	0x0000,0x0000,0x2220,0x0222,0x1120,0x0212,0x2120,0x0212,
	0x2210,0x0212,0x1110,0x0111,0x2220,0x0212,0x0000,0x0010,
	0x0000,0x0000,0x2220,0x0222,0x1110,0x0211,0x2210,0x0222,
	0x2210,0x0222,0x1110,0x0221,0x2220,0x0212,0x1110,0x0011,
	0x0000,0x0000,0x1220,0x0211,0x2120,0x0212,0x2110,0x0222,
	0x1110,0x0221,0x2120,0x0211,0x2120,0x0212,0x1100,0x0011,
	0x0000,0x0000,0x1110,0x0222,0x1210,0x0221,0x2210,0x0221,
	0x1220,0x0221,0x1120,0x0222,0x2120,0x0222,0x0100,0x0000,

	0x0000,0x0000,0x2220,0x0222,0x1120,0x0211,0x1120,0x0212,
	0x1220,0x0221,0x1120,0x0211,0x2210,0x0212,0x0010,0x0011,
	0x0000,0x0000,0x2220,0x0222,0x1220,0x0211,0x1220,0x0112,
	0x1220,0x0111,0x2220,0x0212,0x2220,0x0221,0x1000,0x0001,
	0x0000,0x0000,0x2120,0x0222,0x2120,0x0111,0x2120,0x0121,
	0x2120,0x0121,0x2120,0x0111,0x2220,0x0222,0x0000,0x0000,
	0x0000,0x0000,0x2220,0x0222,0x2120,0x0212,0x2120,0x0212,
	0x2120,0x0212,0x2120,0x0212,0x2220,0x0222,0x0000,0x0000,

	0x0000,0x0000,0x2220,0x0222,0x2120,0x0111,0x2120,0x0121,
	0x2120,0x0112,0x2120,0x0221,0x2220,0x0111,0x0000,0x0000,
	0x0000,0x0000,0x2220,0x0122,0x2220,0x0121,0x2120,0x0121,
	0x2120,0x0111,0x2120,0x0122,0x2220,0x0122,0x0000,0x0000,
	0x0000,0x0000,0x2220,0x0222,0x2210,0x0111,0x2210,0x0221,
	0x2210,0x0111,0x2210,0x0112,0x1220,0x0211,0x0000,0x0000,
	0x0000,0x0000,0x2220,0x0222,0x2210,0x0111,0x2210,0x0221,
	0x2210,0x0111,0x2210,0x0111,0x2220,0x0222,0x0000,0x0000,
};

const unsigned short testPal[256] __attribute__((aligned(4))) __attribute__((visibility("hidden")))=
{
	0x03E0,0x001F,0x7FFF,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,

	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,

	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,

	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
};

//}}BLOCK(test)
