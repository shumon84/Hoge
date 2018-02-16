
//{{BLOCK(tile_map)

//======================================================================
//
//	tile_map, 64x16@8, 
//	+ palette 256 entries, not compressed
//	+ 16 tiles not compressed
//	Total size: 512 + 1024 = 1536
//
//	Time-stamp: 2018-02-16, 20:14:43
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.13
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_TILE_MAP_H
#define GRIT_TILE_MAP_H

#define tile_mapTilesLen 1024
extern const unsigned short tile_mapTiles[512];

#define tile_mapPalLen 512
extern const unsigned short tile_mapPal[256];

#endif // GRIT_TILE_MAP_H

//}}BLOCK(tile_map)
