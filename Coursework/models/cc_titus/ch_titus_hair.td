convert_settings = {
   resample = 0
   mipmap_level = 11
   format_name = "MD+MAK"
   format_descr = "Diff(rgb)+AKill(a)"
   uncompressed_flag = false
   fade_flag = false
   fade_begin = 0
   fade_end = 0
   color = {
      R = 127.000000
      G = 127.000000
      B = 127.000000
      A = 0.000000
   }
   filter = 4
   sharpen = 3
   compressionQuality = 1
   force_use_oxt1_flag = false
   fp16 = false
}
materials = {
   hard = {
      preset = "default"
      game_material = "flesh"
      shaders = {
         glt = {
            no_backface_culling = true
            doubleSidedLighting = "relativeView_HZD"
            no_ssao = true
            metallicTint = [
               0,
               229,
               202,
               172
            ]
            metalness = {
               bias = 0.150000
            }
            second_spec = {
               enabled = true
               metallicTint = [
                  0,
                  191,
                  211,
                  255
               ]
               roughness = {
                  bias = 0.670000
               }
            }
            anisotropic_spec = {
               enabled = true
               angle = 70.000000
               anisotropy = 0.650000
               extra = {
                  anisotropy = 0.400000
                  shift = -0.050000
               }
            }
            roughness = {
               bias = 0.200000
            }
            detail = {
               density = 1.500000
               scale = 0.300000
            }
            subsurface = {
               translucency = {
                  simple = {
                     backLightTint = [
                        255,
                        255,
                        255,
                        150
                     ]
                  }
                  intensity = 1.000000
               }
            }
            tex = {
               det = "shum_06_nm_det"
            }
            covering = {
               coveringMask = "ch_titus_hair_hdetm"
            }
            __type_id = "glt_sh_templ"
         }
      }
      __type_id = "material_templ"
   }
   soft = {
      preset = "default"
      game_material = "flesh"
      shaders = {
         glt = {
            no_backface_culling = true
            doubleSidedLighting = "relativeView_HZD"
            no_ssao = true
            z_func_less = true
            blendMode = "blend"
            metallicTint = [
               0,
               229,
               202,
               172
            ]
            metalness = {
               bias = 0.150000
            }
            second_spec = {
               enabled = true
               metallicTint = [
                  0,
                  191,
                  211,
                  255
               ]
               roughness = {
                  bias = 0.670000
               }
            }
            anisotropic_spec = {
               enabled = true
               angle = 70.000000
               anisotropy = 0.650000
               extra = {
                  anisotropy = 0.400000
                  shift = -0.050000
               }
            }
            roughness = {
               bias = 0.200000
            }
            detail = {
               density = 1.500000
               scale = 0.300000
            }
            subsurface = {
               translucency = {
                  simple = {
                     backLightTint = [
                        255,
                        255,
                        255,
                        150
                     ]
                  }
                  intensity = 1.000000
               }
            }
            tex = {
               det = "shum_06_nm_det"
            }
            covering = {
               coveringMask = "ch_titus_hair_hdetm"
            }
            __type_id = "glt_sh_templ"
         }
      }
      __type_id = "material_templ"
   }
   "hard CAMO" = {
      preset = "default"
      game_material = "flesh"
      shaders = {
         glt = {
            no_backface_culling = true
            metallicTint = [
               0,
               186,
               174,
               174
            ]
            metalness = {
               bias = 0.150000
            }
            second_spec = {
               enabled = true
               metallicTint = [
                  0,
                  127,
                  167,
                  255
               ]
               roughness = {
                  bias = 0.670000
               }
            }
            anisotropic_spec = {
               enabled = true
               anisotropy = 0.570000
               intensity = 2.500000
               extra = {
                  anisotropy = 0.400000
                  shift = 0.250000
               }
            }
            roughness = {
               bias = 0.220000
            }
            detail = {
               density = 1.500000
               scale = 0.300000
            }
            subsurface = {
               translucency = {
                  simple = {
                     backLightTint = [
                        255,
                        255,
                        255,
                        150
                     ]
                  }
                  intensity = 1.000000
               }
            }
            tex = {
               det = "shum_06_nm_det"
            }
            fakeLight = {
               enable = true
            }
            dissolvable = {
               enable = true
            }
            __type_id = "glt_sh_templ"
         }
         sfx = {
            preset = "default"
            emissive = {
               intensity = 100.000000
               adaptiveIntensity = true
            }
            lighting = {
               reflection_intensity = 5.000000
            }
            tint = [
               255,
               28,
               221,
               221
            ]
            overrideAffixScroll = {
               override = true
            }
            softFreshnel = {
               enabled = true
               power = 3.000000
            }
            edgeHighlight = {
               enabled = true
               intensity = 50.000000
               power = 10.000000
               blendMode = "mul"
            }
            scrollSpeedScaleX = 0.000000
            scrollSpeedScaleY = -0.200000
            tex = "phantom_hands"
            layerFirst = {
               textureScaleX = 0.500000
               textureScaleY = 0.500000
            }
            distort = {
               speedScaleX = 1.000000
               speedScaleY = 1.000000
               distortTexture = "part_nm_03_nm"
               distortionScale = 0.000000
            }
            distortBackground = {
               strength = 2.500000
               texture = "part_nm_06_nm"
               speedScaleX = 0.000000
               speedScaleY = -0.060000
               useWCS = true
            }
            noVertexColor = true
            dissolvable = {
               enable = true
               invert = true
            }
            __type_id = "sfx_sh_templ"
         }
         mtl_fill = {
            preset = "default"
            writeDepth = true
            isTransparent = true
            __type_id = "mtl_fill_sh_templ"
         }
      }
      __type_id = "material_templ"
   }
   "soft CAMO" = {
      preset = "default"
      game_material = "flesh"
      shaders = {
         glt = {
            no_backface_culling = true
            z_func_less = true
            blendMode = "blend"
            metallicTint = [
               0,
               186,
               174,
               174
            ]
            metalness = {
               bias = 0.150000
            }
            second_spec = {
               enabled = true
               metallicTint = [
                  0,
                  127,
                  167,
                  255
               ]
               roughness = {
                  bias = 0.670000
               }
            }
            anisotropic_spec = {
               enabled = true
               anisotropy = 0.570000
               intensity = 2.500000
               extra = {
                  anisotropy = 0.400000
                  shift = 0.250000
               }
            }
            roughness = {
               bias = 0.220000
            }
            detail = {
               density = 1.500000
               scale = 0.300000
            }
            subsurface = {
               translucency = {
                  simple = {
                     backLightTint = [
                        255,
                        255,
                        255,
                        150
                     ]
                  }
                  intensity = 1.000000
               }
            }
            tex = {
               det = "shum_06_nm_det"
            }
            fakeLight = {
               enable = true
            }
            dissolvable = {
               enable = true
            }
            __type_id = "glt_sh_templ"
         }
         sfx = {
            preset = "default"
            emissive = {
               intensity = 100.000000
               adaptiveIntensity = true
            }
            lighting = {
               reflection_intensity = 5.000000
            }
            tint = [
               255,
               28,
               221,
               221
            ]
            overrideAffixScroll = {
               override = true
            }
            softFreshnel = {
               enabled = true
               power = 3.000000
            }
            edgeHighlight = {
               enabled = true
               intensity = 50.000000
               power = 10.000000
               blendMode = "mul"
            }
            scrollSpeedScaleX = 0.000000
            scrollSpeedScaleY = -0.200000
            tex = "phantom_hands"
            layerFirst = {
               textureScaleX = 0.500000
               textureScaleY = 0.500000
            }
            distort = {
               speedScaleX = 1.000000
               speedScaleY = 1.000000
               distortTexture = "part_nm_03_nm"
               distortionScale = 0.000000
            }
            distortBackground = {
               strength = 2.500000
               texture = "part_nm_06_nm"
               speedScaleX = 0.000000
               speedScaleY = -0.060000
               useWCS = true
            }
            noVertexColor = true
            dissolvable = {
               enable = true
               invert = true
            }
            __type_id = "sfx_sh_templ"
         }
         mtl_fill = {
            preset = "default"
            writeDepth = true
            isTransparent = true
            __type_id = "mtl_fill_sh_templ"
         }
      }
      __type_id = "material_templ"
   }
}
usage = "MD+MAK"
version = 1
