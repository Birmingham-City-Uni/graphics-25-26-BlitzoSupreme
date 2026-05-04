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
      game_material = "ceramic"
      shaders = {
         glt = {
            covering = {
               coveringMask = "ch_titus_arms_02_hdetm"
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
               tint = [
                  255,
                  252,
                  10,
                  10
               ]
               adaptiveIntensity = true
            }
            tex = {
               NM = "ch_titus_arms_02_damaged_nm"
               spec = "ch_titus_arms_02_damaged_spec"
               diffOverride = "ch_titus_arms_02_damaged"
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
