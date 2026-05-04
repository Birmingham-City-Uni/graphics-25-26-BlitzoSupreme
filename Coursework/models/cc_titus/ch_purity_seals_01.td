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
   filter = 0
   sharpen = 1
   compressionQuality = 3
   force_use_oxt1_flag = false
   fp16 = false
}
materials = {
   default = {
      preset = "default"
      game_material = "plastic"
      shaders = {
         glt = {
            no_backface_culling = true
            doubleSidedLighting = "normal"
            roughness = {
               bias = 0.120000
            }
            __type_id = "glt_sh_templ"
         }
      }
      __type_id = "material_templ"
   }
   vert_anim = {
      preset = "default"
      game_material = "paper"
      shaders = {
         glt = {
            no_backface_culling = true
            roughness = {
               bias = 0.120000
            }
            vertex_animation = {
               enabled = true
               animType = "cloth"
               cloth = {
                  synchronizedWithWindSettings = {
                     globalWindScale = 0.100000
                     maxWindAmplitude = 2.000000
                  }
                  linearWave = {
                     amplitude = 0.700000
                     freq = 1.250000
                  }
                  radialWave = {
                     amplitude = 0.200000
                     freq = 0.700000
                  }
                  wind = {
                     useLCS = true
                     direction = {
                        X = 0.000000
                        Y = -0.500000
                     }
                     gusts = {
                        minFreq = 0.100000
                        maxFreq = 0.400000
                     }
                  }
               }
            }
            __type_id = "glt_sh_templ"
         }
      }
      __type_id = "material_templ"
   }
   default_dead = {
      preset = "default"
      shaders = {
         glt = {
            tex = {
               spec = "ch_purity_seals_d_01_spec"
               diffOverride = "ch_purity_seals_d_01"
            }
            __type_id = "glt_sh_templ"
         }
      }
      __type_id = "material_templ"
   }
}
usage = "MD+MAK"
version = 1
