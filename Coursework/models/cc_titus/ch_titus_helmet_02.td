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
   titlescene = {
      preset = "default"
      game_material = "marine_armor"
      shaders = {
         glt = {
            emissive = {
               intensity = 150.000000
               adaptiveIntensity = true
               bloomIntensity = 8000.000000
            }
            tex = {
               NM = "ch_titus_helmet_02_ts_nm"
               spec = "ch_titus_helmet_02_ts_spec"
               emissiveTex = "ch_titus_helmet_02_ts_em"
               diffOverride = "ch_titus_helmet_02_ts"
            }
            __type_id = "glt_sh_templ"
         }
      }
      __type_id = "material_templ"
   }
   default = {
      preset = "default"
      game_material = "marine_armor"
      shaders = {
         glt = {
            emissive = {
               intensity = 30.000000
               adaptiveIntensity = true
               bloomIntensity = 300.000000
            }
            covering = {
               coveringMask = "ch_titus_helmet_02_hdetm"
            }
            __type_id = "glt_sh_templ"
         }
      }
      __type_id = "material_templ"
   }
   glass = {
      preset = "default"
      game_material = "marine_armor"
      shaders = {
         glt = {
            reflectance = 1.000000
            blendMode = "blend"
            albedo_tint = [
               100,
               237,
               23,
               23
            ]
            metallicTint = [
               125,
               163,
               31,
               31
            ]
            second_spec = {
               metallicTint = [
                  77,
                  239,
                  74,
                  74
               ]
            }
            anisotropic_spec = {
               enabled = true
               angle = 10.000000
               anisotropy = 0.600000
               intensity = 30.000000
            }
            roughness = {
               bias = 0.150000
            }
            combiner = "glass"
            glass = {
               filter = [
                  255,
                  181,
                  188,
                  179
               ]
            }
            __type_id = "glt_sh_templ"
         }
      }
      __type_id = "material_templ"
   }
   damaged = {
      preset = "default"
      game_material = "marine_armor"
      shaders = {
         glt = {
            albedo_tint = [
               255,
               244,
               244,
               244
            ]
            emissive = {
               intensity = 150.000000
               adaptiveIntensity = true
               bloomIntensity = 8000.000000
            }
            tex = {
               NM = "ch_titus_helmet_02_damaged_nm"
               spec = "ch_titus_helmet_02_damaged_spec"
               emissiveTex = "ch_titus_helmet_02_ts_em"
               diffOverride = "ch_titus_helmet_02_damaged"
            }
            covering = {
               coveringMask = "ch_titus_shoulders_02_hdetm"
            }
            __type_id = "glt_sh_templ"
         }
      }
      __type_id = "material_templ"
   }
}
usage = "MD"
version = 1
