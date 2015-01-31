#include "Atlas.h"
#include "utils.h"

Atlas::Atlas()
{
}


Atlas::~Atlas()
{
}

InfoSprite Atlas::get(const string& name)
{
	if(0 < _map.size())
	{
		map<string, InfoSprite>::iterator it = _map.find(name);

		if(_map.end() != it)
		{
			return it->second;
		}
	}

	return InfoSprite(Rect(0.0f, 0.0f, 0.99999f, 0.99999f), 1);
}

void Atlas::add(const string& name, const InfoSprite& info)
{
	_map.insert(map<string, InfoSprite>::value_type(name, info));
}

void Atlas::clear()
{
	_map.clear();
}

bool Atlas::load(const char* fileName)
{
	clear();

	std::vector<char> buffer;

	if(true == utils::loadFromAssets(fileName, buffer))
	{
		json_error_t json_error;

		uzing(json_t*, json_root, json_loadb(&buffer[0], buffer.size(), 0, &json_error))
		{
			uzing(json_t*, json_atlases, json_object_get(json_root, "atlases"))
			{
				int i;
				json_t* json_atlas;

				json_array_foreach(json_atlases, i, json_atlas)
				{
					string name;
					Rect rect;

					{
						uzing(json_t*, json, json_object_get(json_atlas, "name"))
						{
							name = json_string_value(json);
						}
					}

					{
						uzing(json_t*, json, json_object_get(json_atlas, "uv"))
						{
							if(JSON_ARRAY == json_typeof(json))
							{
								float uv[2][2];
								float* p_uv = &uv[0][0];

								int i;
								json_t* json_uv;
								json_array_foreach(json, i, json_uv)
								{
									p_uv[i] = json_real_value(json_uv);
								}

								float all_uv[4][2] = { { uv[0][0], uv[0][1] }, { uv[1][0], uv[0][1] }, { uv[1][0], uv[1][1] }, { uv[0][0], uv[1][1] }, };

								rect.fromFloatArray(all_uv);
							}
						}
					}

					json_int_t cols = 1;

					{
						uzing(json_t*, json, json_object_get(json_atlas, "cols"))
						{
							cols = json_integer_value(json);
						}
					}

					add(name, InfoSprite(rect, cols));
				}
			}

			json_decref(json_root);
			return true;
		}
		else
		{
			printf("Error:json_load_file(%s)(%s)\n", fileName, json_error.text);
		}
	}

	return false;
}

bool Atlas::save(const char* fileName)
{
	uzing(json_t*, json_root, json_object())
	{
		uzing(json_t*, json_array_atlases, json_array())
		{
			if(0 == json_object_set_new(json_root, "atlases", json_array_atlases))
			{
				for(map<string, InfoSprite>::iterator it = _map.begin(); _map.end() != it; ++it)
				{
					uzing(json_t*, json_atlas, json_object())
					{
						if(0 == json_array_append(json_array_atlases, json_atlas))
						{
							if(0 == json_object_set_new(json_atlas, "name", json_string(it->first.c_str())))
							{

							}

							float all_uv[4][2];
							it->second.getRect().toFloatArray(all_uv);
							float uv[2][2] = { { all_uv[0][0], all_uv[0][1] }, { all_uv[2][0], all_uv[2][1] } };
							float* p_uv = &uv[0][0];

							uzing(json_t*, json_array_uv, json_array())
							{
								if(0 == json_object_set_new(json_atlas, "uv", json_array_uv))
								{
									for(int i = 0; i < 4; ++i)
									{
										json_array_append_new(json_array_uv, json_real(p_uv[i]));
									}
								}
							}

							if(0 == json_object_set_new(json_atlas, "cols", json_integer(it->second.getCols())))
							{

							}
						}
						else
						{
							printf("Error:append\n");
						}
					}
					else
					{
						printf("Error:json_object_set_new(classes)\n");
					}
				}

				if(0 == json_dump_file(json_root, fileName, 0))
				{
					printf("OK:(%s)\n", fileName);
					json_decref(json_root);

					return true;
				}
				else
				{
					printf("Error:json_dump_file(%s)\n", fileName);
				}
			}
			else
			{
				printf("Error:json_object_set_new\n");
			}
		}
		else
		{
			printf("Error:json_array\n");
		}

		json_decref(json_root);
	}

	return false;
}

