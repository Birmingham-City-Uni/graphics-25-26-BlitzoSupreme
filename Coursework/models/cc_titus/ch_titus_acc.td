convert_settings = {
   resample = 0
   mipmap_level = 12
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
               bias = 0.060000
            }
            emissive = {
               tint = [
                  255,
                  255,
                  0,
                  0
               ]
               intensity = 10.000000
               adaptiveIntensity = true
               bloomIntensity = 20.000000
            }
            fakeLight = {
               enable = true
            }
            __type_id = "glt_sh_templ"
         }
      }
      __type_id = "material_templ"
   }
   papyrus = {
      preset = "default"
      game_material = "cloth"
      shaders = {
         glt = {
            no_backface_culling = true
            doubleSidedLighting = "normal"
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
               bias = 0.060000
            }
            emissive = {
               tint = [
                  255,
                  255,
                  0,
                  0
               ]
               intensity = 10.000000
               adaptiveIntensity = true
               bloomIntensity = 20.000000
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
   "papyrus CAMO" = {
      preset = "default"
      game_material = "cloth"
      shaders = {
         glt = {
            no_backface_culling = true
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
   "default CC" = {
      preset = "default"
      game_material = "marine_armor"
      shaders = {
         glt = {
            roughness = {
               bias = 0.060000
            }
            emissive = {
               tint = [
                  255,
                  255,
                  0,
                  0
               ]
               intensity = 10.000000
               adaptiveIntensity = true
               bloomIntensity = 20.000000
            }
            tex = {
               diffOverride = "ch_titus_acc_a"
            }
            fakeLight = {
               enable = true
            }
            customization = {
               mask = "ch_titus_acc_cc"
               texArrayDiffuse = ""
               texArrayNormals = ""
               texArraySpec = ""
               texArrayEmissiveMask = ""
               layer0 = {
                  tintBlendMode = "linear_blend"
                  blendMode = "tex_blend"
               }
               layer1 = {
                  tintBlendMode = "linear_blend"
                  blendMode = "tex_blend"
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
               bias = 0.060000
            }
            emissive = {
               tint = [
                  255,
                  255,
                  0,
                  0
               ]
               intensity = 10.000000
               adaptiveIntensity = true
               bloomIntensity = 20.000000
            }
            vertex_animation = {
               cloth = {
                  synchronizedWithWindSettings = {
                     globalWindScale = 0.050000
                     maxWindAmplitude = 3.000000
                     maxAnimationOffset = 10.000000
                  }
               }
               vegetation = {
                  synchronizedWithWindSettings = {
                     globalWindScale = 0.025000
                     maxWindAmplitude = 0.150000
                     leafsSway = {
                        X = 0.000000
                        Y = 0.050000
                        Z = 0.000000
                     }
                     leafsSwayFreq = 2.124000
                     leafsSwayDetailAmp = 0.030000
                     leafsSwayDetailFreq = 3.312000
                  }
               }
            }
            tex = {
               diffOverride = "ch_titus_acc_a"
            }
            fakeLight = {
               enable = true
            }
            customization = {
               mask = "ch_titus_acc_checker_cc"
               texArrayDiffuse = ""
               texArrayNormals = ""
               texArraySpec = ""
               texArrayEmissiveMask = ""
               layer0 = {
                  tintBlendMode = "linear_blend"
                  blendMode = "tex_blend"
               }
               layer1 = {
                  tintBlendMode = "linear_blend"
                  blendMode = "tex_blend"
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
usage = "MD+MAK"
version = 1
