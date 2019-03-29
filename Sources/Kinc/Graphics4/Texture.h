#pragma once

#include <Kore/Graphics1/Image.h>
#include <Kore/TextureImpl.h>

typedef Kinc_G1_Image Kinc_G4_Image;

typedef struct {
	int texWidth;
	int texHeight;
	int texDepth;
//private:
	//void init(const char* format, bool readable = false);
	//void init3D(bool readable = false);
	Kinc_G4_TextureImpl impl;
} Kinc_G4_Texture;

Kinc_G4_Texture *Kinc_G4_Texture_Create(int width, int height, Format format, bool readable);
Kinc_G4_Texture *Kinc_G4_Texture_Create3D(int width, int height, int depth, Format format, bool readable);
//Texture(Kore::Reader &reader, const char *format, bool readable = false);
Kinc_G4_Texture *Kinc_G4_Texture_CreateFromFile(const char *filename, bool readable);
Kinc_G4_Texture *Kinc_G4_Texture_CreateFromBytes(void *data, int size, const char *format, bool readable);
//Kinc_G4_Texture *Kinc_G4_Texture_CreateFromBytes(void *data, int width, int height, int format, bool readable);
Kinc_G4_Texture *Kinc_G4_Texture_CreateFromBytes3D(void *data, int width, int height, int depth, int format, bool readable = false);
#ifdef KORE_ANDROID
Texture(unsigned texid);
#endif
//void _set(TextureUnit unit);
//void _setImage(TextureUnit unit);
unsigned char *Kinc_G4_Texture_Lock(Kinc_G4_Texture *texture);
void Kinc_G4_Texture_Unlock(Kinc_G4_Texture *texture);
void Kinc_G4_Texture_Clear(Kinc_G4_Texture *texture, int x, int y, int z, int width, int height, int depth, unsigned color);
#if defined(KORE_IOS) || defined(KORE_MACOS)
void upload(u8 *data, int stride);
#endif
void Kinc_G4_Texture_GenerateMipmaps(Kinc_G4_Texture *texture, int levels);
void Kinc_G4_Texture_setMipmap(Kinc_G4_Texture *texture, Kinc_G4_Texture *mipmap, int level);

int Kinc_G4_Texture_Stride(Kinc_G4_Texture *texture);