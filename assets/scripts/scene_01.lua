
scene = {
  -- Tabla de imagenes y sprites
  sprites = {
    [0] =
    {assetId = "0_floor", filePath = "./assets/images/floors.png"},
    {assetId = "farmer_idle", filePath = "./assets/images/farmer_idle.png"},
    {assetId = "farmer_walk", filePath = "./assets/images/farmer_walk.png"},
    {assetId = "player", filePath = "./assets/images/player.png"},
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
  },

  -- Tabla de musica
  music = {},

  -- Tabla de fuentes
  fonts = {},

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
    },
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
          position = { x = 375.0, y = 5.0 }, -- TODO: game renders this at x2
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
          position = { x = 135, y = 90 },
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
          position = { x = 130, y = 140 },
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
          position = { x = 130, y = 190 },
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
          width = 8,
          height = 10,
          offset = { x = 4, y = 12 },
        },
        health = {
          maxHealth = 100,
          currentHealth = 100,
        },
        direction = {},
        faction = {
          faction = "player",
        },
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
          src_rect = { x = 16, y = 16 }, -- TODO: overriden by animation
          offset = { x = -16, y = -16 },
        },
        tag = {
          tag = "player",
        },
        transform = {
          position = { x = 480.0, y = 220.0 },
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
  },
}