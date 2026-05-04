convert_settings = {
   resample = 0
   mipmap_level = 12
   format_name = "MD"
   format_descr = "Diff(rgb)"
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
   filter = 0
   sharpen = 1
   compressionQuality = 3
   force_use_oxt1_flag = false
   fp16 = false
}
materials = {
   default = {
      preset = "default"
      game_material = "marine_armor"
      shaders = {
         glt = {
            roughness = {
               bias = 0.050000
            }
            fakeLight = {
               useAdvancedMode = true
               enable = true
               wrapping = 0.400000
               advancedOptions = {
                  edgeLightIntensity = 0.200000
                  edgeLightPower = 1.200000
               }
            }
            __type_id = "glt_sh_templ"
         }
      }
      __type_id = "material_templ"
   }
   "default CAMO" = {
      preset = "default"
      shaders = {
         glt = {
            roughness = {
               scale = 0.960000
            }
            fakeLight = {
               useAdvancedMode = true
               enable = true
               wrapping = 0.400000
               advancedOptions = {
                  edgeLightIntensity = 0.200000
                  edgeLightPower = 1.200000
               }
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
            tex = "phantom_hands"
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
   "default CC" = {
      preset = "default"
      game_material = "marine_armor"
      shaders = {
         glt = {
            roughness = {
               bias = 0.050000
            }
            tex = {
               diffOverride = "ch_titus_body_a"
            }
            fakeLight = {
               useAdvancedMode = true
               enable = true
               wrapping = 0.400000
               advancedOptions = {
                  edgeLightIntensity = 0.200000
                  edgeLightPower = 1.200000
               }
            }
            customization = {
               mask = "ch_titus_body_cc"
               texArrayDiffuse = "ch_custom_01"
               texArrayNormals = "ch_custom_01_nm"
               texArraySpec = "ch_custom_01_spec"
               texArrayEmissiveMask = "ch_custom_01_em"
               layer0 = {
                  tintBlendMode = "linear_blend"
               }
               layer1 = {
                  tintBlendMode = "linear_blend"
               }
               layer2 = {
                  tintBlendMode = "linear_blend"
               }
               layer3 = {
                  tintBlendMode = "linear_blend"
                  enabled = false
               }
            }
            __type_id = "glt_sh_templ"
         }
      }
      __type_id = "material_templ"
   }
   "default CHKR_CC" = {
      preset = "default"
      game_material = "marine_armor"
      shaders = {
         glt = {
            roughness = {
               bias = 0.050000
            }
            tex = {
               diffOverride = "ch_titus_body_a"
            }
            fakeLight = {
               useAdvancedMode = true
               enable = true
               wrapping = 0.400000
               advancedOptions = {
                  edgeLightIntensity = 0.200000
                  edgeLightPower = 1.200000
               }
            }
            customization = {
               mask = "ch_titus_body_checker_cc"
               texArrayDiffuse = "ch_custom_01"
               texArrayNormals = "ch_custom_01_nm"
               texArraySpec = "ch_custom_01_spec"
               texArrayEmissiveMask = "ch_custom_01_em"
               layer0 = {
                  tintBlendMode = "linear_blend"
               }
               layer1 = {
                  tintBlendMode = "linear_blend"
               }
               layer2 = {
                  tintBlendMode = "linear_blend"
               }
               layer3 = {
                  tintBlendMode = "linear_blend"
                  enabled = false
               }
            }
            __type_id = "glt_sh_templ"
         }
      }
      __type_id = "material_templ"
   }
}
usage = "MD"
version = 1
