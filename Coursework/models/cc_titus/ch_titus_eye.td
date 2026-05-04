convert_settings = {
   resample = 0
   mipmap_level = 10
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
      game_material = "flesh"
      shaders = {
         glt = {
            blurShadows = "high"
            roughness = {
               bias = 0.120000
            }
            parallax = {
               scale = 2.000000
            }
            nmScale = 1.300000
            combiner = "eyes"
            eyes = {
               roughness = {
                  scale = 0.010000
               }
               x = 0.000000
               y = 0.000000
               nmScale = 4.000000
            }
            __type_id = "glt_sh_templ"
         }
      }
      __type_id = "material_templ"
   }
   eyes2 = {
      preset = "default"
      game_material = "flesh"
      shaders = {
         glt = {
            tex = {
               NM = "test_sclera_02_nm"
               diffOverride = "test_sclera_02"
            }
            combiner = "eyes2"
            __type_id = "glt_sh_templ"
         }
      }
      __type_id = "material_templ"
   }
}
usage = "MD"
version = 1
