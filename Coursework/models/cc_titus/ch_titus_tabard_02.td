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
      shaders = {
         glt = {
            no_backface_culling = true
            doubleSidedLighting = "normal"
            second_spec = {
               metallicTint = [
                  0,
                  193,
                  221,
                  255
               ]
            }
            anisotropic_spec = {
               angle = 0.000000
               anisotropy = 0.200000
               intensity = 0.800000
               extra = {
                  anisotropy = 0.400000
               }
            }
            detail = {
               density = 30.000000
            }
            subsurface = {
               translucency = {
                  mode = "simple"
               }
            }
            tex = {
               det = "detail_13_det"
            }
            covering = {
               coveringMask = "ch_titus_tabard_02_hdetm"
            }
            __type_id = "glt_sh_templ"
         }
      }
      __type_id = "material_templ"
   }
}
usage = "MD+MAK"
version = 1
