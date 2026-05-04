convert_settings = {
   resample = 0
   mipmap_level = 12
   format_name = "MD+MT"
   format_descr = "Diff(rgb)+Transp(a)"
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
      game_material = "flesh"
      shaders = {
         glt = {
            reflectance = 0.250000
            second_spec = {
               enabled = true
               metallicTint = [
                  0,
                  0,
                  135,
                  255
               ]
               metalness = {
                  bias = 0.200000
               }
               roughness = {
                  scale = 1.000000
                  bias = 0.160000
               }
            }
            anisotropic_spec = {
               enabled = true
               anisotropy = 0.050000
               intensity = 4.000000
               extra = {
                  anisotropy = 0.250000
                  intensity = 2.000000
               }
            }
            roughness = {
               bias = 0.070000
            }
            detail = {
               density = 22.000000
               scale = 0.300000
            }
            reflection = {
               disableSSR = true
            }
            subsurface = {
               scattering = {
                  profile = "preset_1"
                  useDiffAlphaMask = true
               }
            }
            tex = {
               det = "leather_02_det"
            }
            __type_id = "glt_sh_templ"
         }
      }
      __type_id = "material_templ"
   }
   metal = {
      preset = "default"
      game_material = "metal"
      __type_id = "material_templ"
   }
}
usage = "MD+MT"
version = 1
