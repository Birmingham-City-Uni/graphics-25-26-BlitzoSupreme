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
      game_material = "cloth"
      __type_id = "material_templ"
   }
   green = {
      preset = "default"
      game_material = "cloth"
      shaders = {
         glt = {
            tex = {
               diffOverride = "ch_rope_constructor_02"
            }
            __type_id = "glt_sh_templ"
         }
      }
      __type_id = "material_templ"
   }
   tank_hero = {
      preset = "default"
      game_material = "cloth"
      shaders = {
         glt = {
            tex = {
               diffOverride = "ch_rope_constructor_03"
            }
            __type_id = "glt_sh_templ"
         }
      }
      __type_id = "material_templ"
   }
}
usage = "MD+MAK"
version = 1
