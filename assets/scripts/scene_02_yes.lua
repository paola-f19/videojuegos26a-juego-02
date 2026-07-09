
scene = {
  -- Tabla de imagenes y sprites
  sprites = {
    [0] =
    {assetId = "0_floor", filePath = "./assets/images/floors.png"},
    {assetId = "0_ranch_props", filePath = "./assets/images/ranch_props.png"},
    {assetId = "0_farming_props", filePath = "./assets/images/farming_props.png"},
    {assetId = "farmer_idle", filePath = "./assets/images/farmer_idle.png"},
    {assetId = "farmer_walk", filePath = "./assets/images/farmer_walk.png"},
    {assetId = "player", filePath = "./assets/images/player.png"},
    {assetId = "bamboo", filePath = "./assets/images/bamboo.png"},
    {assetId = "berry", filePath = "./assets/images/berry.png"},
    {assetId = "berry_seeds", filePath = "./assets/images/berry_seeds.png"},
    {assetId = "beast_idle", filePath = "./assets/images/beast_idle.png"},
    {assetId = "beast_product", filePath = "./assets/images/beast_product.png"},
    {assetId = "bird_idle", filePath = "./assets/images/bird_idle.png"},
    {assetId = "bird_product", filePath = "./assets/images/bird_product.png"},
    {assetId = "carrot", filePath = "./assets/images/carrot.png"},
    {assetId = "carrot_seeds", filePath = "./assets/images/carrot_seeds.png"},
    {assetId = "dragon_idle", filePath = "./assets/images/dragon_idle.png"},
    {assetId = "dragon_product", filePath = "./assets/images/dragon_product.png"},
    {assetId = "cleaning_kit", filePath = "./assets/images/cleaning_kit.png"},
    {assetId = "knife", filePath = "./assets/images/knife.png"},
    {assetId = "guide_glove", filePath = "./assets/images/glove.png"},
    {assetId = "meat", filePath = "./assets/images/meat.png"},
    {assetId = "mollusc_idle", filePath = "./assets/images/mollusc_idle.png"},
    {assetId = "mollusc_product", filePath = "./assets/images/mollusc_product.png"},
    {assetId = "radish", filePath = "./assets/images/radish.png"},
    {assetId = "radish_seeds", filePath = "./assets/images/radish_seeds.png"},
    {assetId = "pumpkin", filePath = "./assets/images/pumpkin.png"},
    {assetId = "pumpkin_seeds", filePath = "./assets/images/pumpkin_seeds.png"},
    {assetId = "sickle", filePath = "./assets/images/sickle.png"},
    {assetId = "slime_idle", filePath = "./assets/images/slime_idle.png"},
    {assetId = "slime_product", filePath = "./assets/images/spit.png"},
    {assetId = "sugarcane_idle", filePath = "./assets/images/sugarcane_idle.png"},
    {assetId = "sugarcane_product", filePath = "./assets/images/sugarcane_product.png"},
    {assetId = "trex_idle", filePath = "./assets/images/trex_idle.png"},
    {assetId = "trex_product", filePath = "./assets/images/trex_product.png"},
    {assetId = "watering_can", filePath = "./assets/images/watering_can.png"},
    {assetId = "settings", filePath = "./assets/images/Settings.png"},
  },

  -- Tabla con la info de las animaciones
  animations = {
    [0] = 
    {
      animation_id = "player_idle_front",
      texture_id = "farmer_idle",
      row = 0,
      w = 32,
      h = 32,
      num_frames = 1,
      speed_rate = 15,
      is_loop = true,
    },
    {
      animation_id = "player_idle_side",
      texture_id = "farmer_idle",
      row = 2,
      w = 32,
      h = 32,
      num_frames = 1,
      speed_rate = 15,
      is_loop = true,
    },
        {
      animation_id = "player_idle_back",
      texture_id = "farmer_idle",
      row = 3,
      w = 32,
      h = 32,
      num_frames = 1,
      speed_rate = 15,
      is_loop = true,
    },
    {
      animation_id = "player_run_side",
      texture_id = "farmer_walk",
      row = 2,
      w = 32,
      h = 32,
      num_frames = 3,
      speed_rate = 15,
      is_loop = true,
    },
    {
      animation_id = "player_run_up",
      texture_id = "farmer_walk",
      row = 3,
      w = 32,
      h = 32,
      num_frames = 3,
      speed_rate = 15,
      is_loop = true,
    },
    {
      animation_id = "player_run_down",
      texture_id = "farmer_walk",
      row = 0,
      w = 32,
      h = 32,
      num_frames = 3,
      speed_rate = 15,
      is_loop = true,
    },
    {
      animation_id = "beast_idle",
      texture_id = "beast_idle",
      row = 0,
      w = 16,
      h = 16,
      num_frames = 4,
      speed_rate = 8,
      is_loop = true,
    },
    {
      animation_id = "bird_idle",
      texture_id = "bird_idle",
      row = 0,
      w = 16,
      h = 16,
      num_frames = 4,
      speed_rate = 8,
      is_loop = true,
    },
    {
      animation_id = "dragon_idle",
      texture_id = "dragon_idle",
      row = 0,
      w = 16,
      h = 16,
      num_frames = 4,
      speed_rate = 8,
      is_loop = true,
    },
    {
      animation_id = "mollusc_idle",
      texture_id = "mollusc_idle",
      row = 0,
      w = 16,
      h = 16,
      num_frames = 4,
      speed_rate = 8,
      is_loop = true,
    },
    {
      animation_id = "slime_idle",
      texture_id = "slime_idle",
      row = 0,
      w = 16,
      h = 16,
      num_frames = 4,
      speed_rate = 8,
      is_loop = true,
    },
    {
      animation_id = "sugarcane_idle",
      texture_id = "sugarcane_idle",
      row = 0,
      w = 16,
      h = 16,
      num_frames = 4,
      speed_rate = 8,
      is_loop = true,
    },
    {
      animation_id = "trex_idle",
      texture_id = "trex_idle",
      row = 0,
      w = 16,
      h = 16,
      num_frames = 4,
      speed_rate = 8,
      is_loop = true,
    },
    -- attacks
    -- {
    --   animation_id = "player_attack_side",
    --   texture_id = "player",
    --   row = 7,
    --   w = 48,
    --   h = 48,
    --   num_frames = 4,
    --   speed_rate = 15,
    --   is_loop = false,
    -- },
    -- {
    --   animation_id = "player_attack_up",
    --   texture_id = "player",
    --   row = 8,
    --   w = 48,
    --   h = 48,
    --   num_frames = 4,
    --   speed_rate = 15,
    --   is_loop = false,
    -- },
    -- {
    --   animation_id = "player_attack_down",
    --   texture_id = "player",
    --   row = 6,
    --   w = 48,
    --   h = 48,
    --   num_frames = 4,
    --   speed_rate = 15,
    --   is_loop = false,
    -- },
  },

  -- Tabla de efectos de sonido
  sounds = {
    [0] =
    {id = "slash", filePath = "./assets/audio/Slash.wav"},
    {id = "hurt", filePath = "./assets/audio/Impact2.wav"},
    {id = "restore", filePath = "./assets/audio/Strange.wav"},
    {id = "gameOver", filePath = "./assets/audio/GameOver.wav"},
    {id = "win", filePath = "./assets/audio/Success3.wav"},
    {id = "watering_can", filePath = "./assets/audio/Water10.wav"},
    {id = "seed_pouch", filePath = "./assets/audio/Grass.wav"},
    {id = "pickup", filePath = "./assets/audio/Alert2.wav"},
  },

  -- Tabla de musica
  music = {},

  -- Tabla de fuentes
  fonts = {
    [0] = 
    {fontId = "press_start_8", filePath = "./assets/fonts/press_start.ttf", fontSize = 8},
    {fontId = "press_start_16", filePath = "./assets/fonts/press_start.ttf", fontSize = 16},
    {fontId = "press_start_24", filePath = "./assets/fonts/press_start.ttf", fontSize = 24},
  },

  -- Tabla de acciones y teclas
  keys = {
    [0] = 
    {name = "up", key = 119},
    {name = "left", key = 97},
    {name = "down", key = 115},
    {name = "right", key = 100},
  },

  -- Tabla de acciones y botones de raton
  buttons = {
    [0] = 
    {name = "mouse_left_button", button = 1},
  },

  -- Tabla de mapa
  maps = {
    map_path = "./assets/maps/level_01.tmx",
    tilesets = {
      [0] =
      {name = "0_floor", path = "./assets/maps/floors.tsx"},
      {name = "0_ranch_props", path = "./assets/maps/ranch_props.tsx"},
      {name = "0_farming_props", path = "./assets/maps/farming_props.tsx"},
    },
  },

  -- Tabla de items
  items =  {
    [0] = 
    {id = "sickle", texture = "sickle", consumable = false, width = 16, height = 16, src_rect = { x = 0, y = 0 }},
    {id = "watering_can", texture = "watering_can", consumable = false, width = 16, height = 16, src_rect = { x = 0, y = 0 }},
    {id = "bamboo", texture = "bamboo", consumable = true, width = 16, height = 16, src_rect = { x = 0, y = 0 }},
    {id = "berry", texture = "berry", consumable = true, width = 16, height = 16, src_rect = { x = 0, y = 0 }},
    {id = "berry_seeds", texture = "berry_seeds", consumable = true, width = 16, height = 16, src_rect = { x = 0, y = 0 }},
    {id = "beast_product", texture = "beast_product", consumable = false, width = 16, height = 16, src_rect = { x = 0, y = 0 }},
    {id = "bird_product", texture = "bird_product", consumable = false, width = 16, height = 16, src_rect = { x = 0, y = 0 }},
    {id = "dragon_product", texture = "dragon_product", consumable = false, width = 16, height = 16, src_rect = { x = 0, y = 0 }},
    {id = "carrot", texture = "carrot", consumable = true, width = 16, height = 16, src_rect = { x = 16, y = 0 }},
    {id = "carrot_seeds", texture = "carrot_seeds", consumable = true, width = 16, height = 16, src_rect = { x = 0, y = 0 }},
    {id = "cleaning_kit", texture = "cleaning_kit", consumable = false, width = 16, height = 16, src_rect = { x = 0, y = 0 }},
    {id = "knife", texture = "knife", consumable = false, width = 16, height = 16, src_rect = { x = 0, y = 0 }},
    {id = "guide_glove", texture = "guide_glove", consumable = false, width = 16, height = 16, src_rect = { x = 0, y = 0 }},
    {id = "meat", texture = "meat", consumable = true, width = 16, height = 16, src_rect = { x = 0, y = 0 }},
    {id = "mollusc_product", texture = "mollusc_product", consumable = false, width = 16, height = 16, src_rect = { x = 0, y = 0 }},
    {id = "slime_product", texture = "slime_product", consumable = false, width = 16, height = 16, src_rect = { x = 0, y = 0 }},
    {id = "sugarcane_product", texture = "sugarcane_product", consumable = true, width = 16, height = 16, src_rect = { x = 0, y = 0 }},
    {id = "trex_product", texture = "trex_product", consumable = false, width = 16, height = 16, src_rect = { x = 0, y = 0 }},
    {id = "radish", texture = "radish", consumable = true, width = 16, height = 16, src_rect = { x = 16, y = 0 }},
    {id = "radish_seeds", texture = "radish_seeds", consumable = true, width = 16, height = 16, src_rect = { x = 0, y = 0 }},
    {id = "pumpkin", texture = "pumpkin", consumable = true, width = 16, height = 16, src_rect = { x = 16, y = 0 }},
    {id = "pumpkin_seeds", texture = "pumpkin_seeds", consumable = true, width = 16, height = 16, src_rect = { x = 0, y = 0 }},
    {id = "seed_pouch", texture = "0_farming_props", consumable = false, width = 16, height = 16, src_rect = { x = 0, y = 48 }},
  },

  -- Tabla de ordenes
  orders = {
    [0] =
    {item = "slime_product", quantity = 4},
    {item = "bird_product", quantity = 3},
    {item = "sugarcane_product", quantity = 4},
    {item = "beast_product", quantity = 3},
  },

  -- Tabla de entidades
  entities = {
    [0] =
    -- Pause button
    {
      components = {
        clickable = {},
        sprite = {
          assetId = "settings",
          width = 20,
          height = 20,
          src_rect = { x = 0, y = 0 },
          offset = { x = 0, y = 0 },
        },
        script = {
          path = "./assets/scripts/pause.lua",
        },
        transform = {
          position = { x = 475.0, y = 5.0 }, -- TODO: game renders this at x2
          scale = { x = 0.80, y = 0.80 },
          rotation = 0.0,
        },
        ui = {},
      },
    },
    -- Pause text
    {
      components = {
        ui = {},
        pause_menu = {},
        text = {
          text = "Paused",
          fontId = "press_start_24",
          r = 255,
          g = 255,
          b = 255,
          a = 255,
        },
        transform = {
          position = { x = 180, y = 90 },
          scale = { x = 1.0, y = 1.0 },
          rotation = 0.0,
        },
      },
    },
    -- Resume button
    {
      components = {
        clickable = {},
        pause_menu = {},
        text = {
          text = "Resume",
          fontId = "press_start_16",
          r = 0,
          g = 0,
          b = 0,
          a = 0,
        },
        transform = {
          position = { x = 175, y = 140 },
          scale = { x = 1.0, y = 1.0 },
          rotation = 0.0,
        },
        ui = {},
        ui_rect = {
          width = 150,
          height = 40,
          color = { r = 245, g = 245, b = 245, a = 245 },
        },
        script = {
          path = "./assets/scripts/pause.lua",
        },
      },
    },
    -- Main menu button
    {
      components = {
        clickable = {},
        pause_menu = {},
        text = {
          text = "Main Menu",
          fontId = "press_start_16",
          r = 0,
          g = 0,
          b = 0,
          a = 0,
        },
        transform = {
          position = { x = 175, y = 190 },
          scale = { x = 1.0, y = 1.0 },
          rotation = 0.0,
        },
        ui = {},
        ui_rect = {
          width = 150,
          height = 40,
          color = { r = 245, g = 245, b = 245, a = 245 },
        },
        script = {
          path = "./assets/scripts/menu_button.lua",
        },
      },
    },
    -- Item on ground test 1
    {
      components = {
        box_collider = {
          width = 16,
          height = 16,
          offset = { x = 0, y = 0 },
        },
        item = {
          id = "sickle"
        },
        sprite = {
          assetId = "sickle",
          width = 16,
          height = 16,
          src_rect = { x = 0, y = 0 },
          offset = { x = 0, y = 0 },
        },
        transform = {
          position = { x = 385.0, y = 65.0 },
          scale = { x = 1.0, y = 1.0 },
          rotation = 0.0,
        },
      },
    },
    -- Item on ground test 1
    {
      components = {
        box_collider = {
          width = 16,
          height = 16,
          offset = { x = 0, y = 0 },
        },
        item = {
          id = "watering_can"
        },
        sprite = {
          assetId = "watering_can",
          width = 16,
          height = 16,
          src_rect = { x = 0, y = 0 },
          offset = { x = 0, y = 0 },
        },
        transform = {
          position = { x = 370.0, y = 65.0 },
          scale = { x = 1.0, y = 1.0 },
          rotation = 0.0,
        },
      },
    },
    -- Item on ground test 2
    {
      components = {
        box_collider = {
          width = 16,
          height = 16,
          offset = { x = 0, y = 0 },
        },
        item = {
          id = "seed_pouch"
        },
        sprite = {
          assetId = "0_farming_props",
          width = 16,
          height = 16,
          src_rect = { x = 0, y = 48 },
          offset = { x = 0, y = 0 },
        },
        transform = {
          position = { x = 355.0, y = 65.0 },
          scale = { x = 1.0, y = 1.0 },
          rotation = 0.0,
        },
      },
    },
    -- Item on ground test 1
    {
      components = {
        box_collider = {
          width = 16,
          height = 16,
          offset = { x = 0, y = 0 },
        },
        item = {
          id = "guide_glove"
        },
        sprite = {
          assetId = "guide_glove",
          width = 16,
          height = 16,
          src_rect = { x = 0, y = 0 },
          offset = { x = 0, y = 0 },
        },
        transform = {
          position = { x =600.0, y = 300.0 },
          scale = { x = 1.0, y = 1.0 },
          rotation = 0.0,
        },
      },
    },
        -- Item on ground test 1
    {
      components = {
        box_collider = {
          width = 16,
          height = 16,
          offset = { x = 0, y = 0 },
        },
        item = {
          id = "cleaning_kit"
        },
        sprite = {
          assetId = "cleaning_kit",
          width = 16,
          height = 16,
          src_rect = { x = 0, y = 0 },
          offset = { x = 0, y = 0 },
        },
        transform = {
          position = { x =600.0, y = 350.0 },
          scale = { x = 1.0, y = 1.0 },
          rotation = 0.0,
        },
      },
    },
    -- Zones
        {
      components = {
        box_collider = {
          width = 274,
          height = 274,
          offset = { x = 0, y = 0 },
        },
        rigid_body = {
          is_dynamic = false,
          is_solid = false,
          mass = 0,
        },
        tag = {
          tag = "happy_zone",
        },
        transform = {
          position = { x = 310.0, y = 485.0 },
          scale = { x = 1.0, y = 1.0 },
          rotation = 0.0,
        },
        zone = {},
      },
    },
    -- Slime Zone
    {
      components = {
        box_collider = {
          width = 148,
          height = 120,
          offset = { x = 0, y = 0 },
        },
        rigid_body = {
          is_dynamic = false,
          is_solid = false,
          mass = 0,
        },
        tag = {
          tag = "slime_zone",
        },
        transform = {
          position = { x = 710.0, y = 225.0 },
          scale = { x = 1.0, y = 1.0 },
          rotation = 0.0,
        },
        zone = {},
      },
    },
    -- Sugarcane Zone
    {
      components = {
        box_collider = {
          width = 148,
          height = 120,
          offset = { x = 0, y = 0 },
        },
        rigid_body = {
          is_dynamic = false,
          is_solid = false,
          mass = 0,
        },
        tag = {
          tag = "sugarcane_zone",
        },
        transform = {
          position = { x = 40.0, y = 405.0 },
          scale = { x = 1.0, y = 1.0 },
          rotation = 0.0,
        },
        zone = {},
      },
    },
    -- Bird Zone
    {
      components = {
        box_collider = {
          width = 148,
          height = 120,
          offset = { x = 0, y = 0 },
        },
        rigid_body = {
          is_dynamic = false,
          is_solid = false,
          mass = 0,
        },
        tag = {
          tag = "bird_zone",
        },
        transform = {
          position = { x = 40.0, y = 225.0 },
          scale = { x = 1.0, y = 1.0 },
          rotation = 0.0,
        },
        zone = {},
      },
    },
    -- Beast Zone
    {
      components = {
        box_collider = {
          width = 148,
          height = 120,
          offset = { x = 0, y = 0 },
        },
        rigid_body = {
          is_dynamic = false,
          is_solid = false,
          mass = 0,
        },
        tag = {
          tag = "beast_zone",
        },
        transform = {
          position = { x = 710.0, y = 405.0 },
          scale = { x = 1.0, y = 1.0 },
          rotation = 0.0,
        },
        zone = {},
      },
    },
    -- Mollusc Zone
    {
      components = {
        box_collider = {
          width = 148,
          height = 120,
          offset = { x = 0, y = 0 },
        },
        rigid_body = {
          is_dynamic = false,
          is_solid = false,
          mass = 0,
        },
        tag = {
          tag = "mollusc_zone",
        },
        transform = {
          position = { x = 40.0, y = 50.0 },
          scale = { x = 1.0, y = 1.0 },
          rotation = 0.0,
        },
        zone = {},
      },
    },
    -- Trex Zone
    {
      components = {
        box_collider = {
          width = 148,
          height = 120,
          offset = { x = 0, y = 0 },
        },
        rigid_body = {
          is_dynamic = false,
          is_solid = false,
          mass = 0,
        },
        tag = {
          tag = "trex_zone",
        },
        transform = {
          position = { x = 710.0, y = 580.0 },
          scale = { x = 1.0, y = 1.0 },
          rotation = 0.0,
        },
        zone = {},
      },
    },
    -- Dragon Zone
    {
      components = {
        box_collider = {
          width = 148,
          height = 120,
          offset = { x = 0, y = 0 },
        },
        rigid_body = {
          is_dynamic = false,
          is_solid = false,
          mass = 0,
        },
        tag = {
          tag = "dragon_zone",
        },
        transform = {
          position = { x = 40.0, y = 580.0 },
          scale = { x = 1.0, y = 1.0 },
          rotation = 0.0,
        },
        zone = {},
      },
    },
    -- Player
    -- last on the list so it renders on top of all other entities
    {
      components = {
        animation = {
          id = "player_idle_front",
        },
        attack = {
          damage = 10,
          range = 16.0,
          duration = 0.12,
          cooldown = 0.40,
        },
        camera_follow = {},
        box_collider = {
          width = 16,
          height = 16,
          offset = { x = 8, y = 8 },
        },
        health = {
          maxHealth = 100,
          currentHealth = 100,
        },
        direction = {},
        faction = {
          faction = "player",
        },
        inventory = {},
        player = {},
        rigid_body = {
          is_dynamic = false,
          is_solid = true,
          mass = 10,
        },
        sanity = {
          maxSanity = 100,
          currentSanity = 100,
          drain = 0,
        },
        script = {
          path = "./assets/scripts/player.lua",
        },
        sprite = {
          assetId = "farmer_idle",
          width = 48,
          height = 48,
          src_rect = { x = 0, y = 0 }, -- TODO: overriden by animation
          offset = { x = 0, y = 0 },
        },
        tag = {
          tag = "player",
        },
        transform = {
          position = { x = 435.0, y = 140.0 },
          scale = { x = 1.0, y = 1.0 },
          rotation = 0.0,
        },
      },
    },
    -- Health bar
    {
      components = {
        bar = {
          width = 100,
          height = 10,
          posX = 10,
          posY = 10,
          fgColor = { r = 0, g = 255, b = 0, a = 255 },
          bgColor = { r = 60, g = 60, b = 60, a = 255 },
          type = "health"
        }, 
      },
    },
    -- Sanity bar
    {
      components = {
        bar = {
          width = 100,
          height = 10,
          posX = 10,
          posY = 25,
          fgColor = { r = 100, g = 149, b = 237, a = 255 },
          bgColor = { r = 60, g = 60, b = 60, a = 255 },
          type = "sanity"
        }, 
      },
    },
    -- Animals
    -- Slime
    {
      components = {
        animation = {
          id = "slime_idle",
        },
        box_collider = {
          width = 16,
          height = 16,
          offset = { x = 0, y = 0 },
        },
        animal_leader = {
          product_id = "slime_product",
          max_happiness = 110,
          current_happiness = 110,
          max_hunger = 110,
          current_hunger = 110,
          max_cleanliness = 110,
          current_cleanliness = 110,
          count = 1,
          production_interval = 10,
          decay_rate = 2.0,
          threshold = 40
        },
        faction = {
          faction = "animal",
        },
        rigid_body = {
          is_dynamic = false,
          is_solid = false,
          mass = 10,
        },
        script = {
          path = "./assets/scripts/slime_leader.lua",
        },
        sprite = {
          assetId = "slime_idle",
          width = 16,
          height = 16,
          src_rect = { x = 0, y = 0 }, -- TODO: overriden by animation
          offset = { x = 0, y = 0 },
        },
        tag = {
          tag = "animal_slime",
        },
        follow = {
          speed = 100,
          is_following = false,
        },
        transform = {
          position = { x =750.0, y = 280.0 },
          scale = { x = 1.0, y = 1.0 },
          rotation = 0.0,
        },
      },
    },
    -- Sugarcane
    {
      components = {
        animation = {
          id = "sugarcane_idle",
        },
        box_collider = {
          width = 16,
          height = 16,
          offset = { x = 0, y = 0 },
        },
        animal_leader = {
          product_id = "sugarcane_product",
          max_happiness = 300,
          current_happiness = 300,
          max_hunger = 100,
          current_hunger = 100,
          max_cleanliness = 300,
          current_cleanliness = 300,
          count = 1,
          production_interval = 10,
          decay_rate = 2.0,
          threshold = 40
        },
        faction = {
          faction = "animal",
        },
        rigid_body = {
          is_dynamic = false,
          is_solid = false,
          mass = 10,
        },
        sprite = {
          assetId = "sugarcane_idle",
          width = 16,
          height = 16,
          src_rect = { x = 0, y = 0 }, -- TODO: overriden by animation
          offset = { x = 0, y = 0 },
        },
        tag = {
          tag = "animal_sugarcane",
        },
        follow = {
          speed = 100,
          is_following = false,
        },
        transform = {
          position = { x = 100.0, y = 440.0 },
          scale = { x = 1.0, y = 1.5 },
          rotation = 0.0,
        },
      },
    },
    -- Bird
    {
      components = {
        animation = {
          id = "bird_idle",
        },
        box_collider = {
          width = 16,
          height = 16,
          offset = { x = 0, y = 0 },
        },
        animal_leader = {
          product_id = "bird_product",
          max_happiness = 60,
          current_happiness = 60,
          max_hunger = 100,
          current_hunger = 100,
          max_cleanliness = 100,
          current_cleanliness = 100,
          count = 1,
          production_interval = 10,
          decay_rate = 2.0,
          threshold = 20
        },
        faction = {
          faction = "animal",
        },
        rigid_body = {
          is_dynamic = false,
          is_solid = false,
          mass = 10,
        },
        sprite = {
          assetId = "bird_idle",
          width = 16,
          height = 16,
          src_rect = { x = 0, y = 0 }, -- TODO: overriden by animation
          offset = { x = 0, y = 0 },
        },
        tag = {
          tag = "animal_bird",
        },
        follow = {
          speed = 100,
          is_following = false,
        },
        transform = {
          position = { x = 100.0, y = 280.0 },
          scale = { x = 1.0, y = 1.0 },
          rotation = 0.0,
        },
      },
    },
    -- Beast
    {
      components = {
        animation = {
          id = "beast_idle",
        },
        box_collider = {
          width = 16,
          height = 16,
          offset = { x = 0, y = 0 },
        },
        animal_leader = {
          product_id = "beast_product",
          max_happiness = 110,
          current_happiness = 110,
          max_hunger = 50,
          current_hunger = 50,
          max_cleanliness = 110,
          current_cleanliness = 110,
          count = 1,
          production_interval = 10,
          decay_rate = 2.0,
          threshold = 20
        },
        faction = {
          faction = "animal",
        },
        rigid_body = {
          is_dynamic = false,
          is_solid = false,
          mass = 10,
        },
        sprite = {
          assetId = "beast_idle",
          width = 16,
          height = 16,
          src_rect = { x = 0, y = 0 }, -- TODO: overriden by animation
          offset = { x = 0, y = 0 },
        },
        tag = {
          tag = "animal_beast",
        },
        follow = {
          speed = 100,
          is_following = false,
        },
        transform = {
          position = { x = 750.0, y = 440.0 },
          scale = { x = 1.5, y = 1.5 },
          rotation = 0.0,
        },
      },
    },
  },
}