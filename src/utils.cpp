#include "utils.h"
#include "png.h"

namespace utils
{
	FILE* openCheckPNG(const char* fileName)
	{
		if(FILE* pFILE = fopen(fileName, "rb"))
		{
			png_byte buf[4];

			if(4 == fread(buf, 1, 4, pFILE))
			{
				if(0 == png_sig_cmp(buf, (png_size_t)0, 4))
				{
					return pFILE;
				}
			}

			fclose(pFILE);
		}

		return NULL;
	}

	bool loadPNGToMemory(const char* fileName, uint* width, uint* height, uint* bpp, vector<uchar>& data)
	{
		if(FILE* pFILE = openCheckPNG(fileName))
		{
			if(png_structp png_ptr = png_create_read_struct(PNG_LIBPNG_VER_STRING, 0, 0, 0))
			{
				if(png_infop info_ptr = png_create_info_struct(png_ptr))
				{
					png_init_io(png_ptr, pFILE);
					png_set_sig_bytes(png_ptr, 4);
					png_read_info(png_ptr, info_ptr);

					png_uint_32 w;
					png_uint_32 h;
					int bit_depth;
					int color_type;

					png_get_IHDR(png_ptr, info_ptr, &w, &h, &bit_depth, &color_type, 0, 0, 0);

					if(16 == bit_depth)
					{
						png_set_strip_16(png_ptr);
					}

					if(PNG_COLOR_TYPE_PALETTE == color_type)
					{
						png_set_expand(png_ptr);
					}

					if(8 > bit_depth)
					{
						png_set_expand(png_ptr);
					}

					if(0 != png_get_valid(png_ptr, info_ptr, PNG_INFO_tRNS))
					{
						png_set_expand(png_ptr);
					}

					if((PNG_COLOR_TYPE_GRAY == color_type) || (PNG_COLOR_TYPE_GRAY_ALPHA == color_type))
					{
						png_set_gray_to_rgb(png_ptr);
					}

					png_read_update_info(png_ptr, info_ptr);
					png_get_IHDR(png_ptr, info_ptr, &w, &h, &bit_depth, &color_type, 0, 0, 0);

					png_uint_32 row_bytes = (png_uint_32)png_get_rowbytes(png_ptr, info_ptr);
					png_uint_32 channels = png_get_channels(png_ptr, info_ptr);

					data.resize(w * h * channels);

					*width = w;
					*height = h;
					*bpp = channels;

					if(png_byte* bytes = (png_byte*)&data[0])
					{
						for(uint i = 0; i < h; ++i)
						{
							png_read_row(png_ptr, bytes + row_bytes * (h - 1 - i), NULL);
						}

						png_read_end(png_ptr, NULL);

						png_destroy_info_struct(png_ptr, &info_ptr);
						png_destroy_read_struct(&png_ptr, 0, 0);
						fclose(pFILE);

						return true;
					}

					png_destroy_info_struct(png_ptr, &info_ptr);
				}

				png_destroy_read_struct(&png_ptr, 0, 0);
			}

			fclose(pFILE);
		}

		return false;
	}

#if IS_PLATFORM_ANDROID
	extern "C" bool jni_loadFromAssets(const char* fileName, std::vector<char>& buffer);

	bool loadFromAssets(const char* fileName, std::vector<char>& buffer)
	{
		return jni_LoadFromAssets(fileName, buffer);
	}
#else
	bool loadFromAssets(const char* fileName, std::vector<char>& buffer)
	{
		if(FILE* file = fopen(fileName, "rb"))
		{
			fseek(file, 0, SEEK_END);

			fpos_t fpos;
			fgetpos(file, &fpos);

			fseek(file, 0, SEEK_SET);

#if defined(__linux)
			if(size_t size = fpos.__pos)
#else
			if(size_t size = fpos)
#endif
			{
				buffer.resize(size);
				fread(&buffer[0], size, 1, file);
			}

			fclose(file);

			return true;
		}

		return false;
	}
#endif

}
