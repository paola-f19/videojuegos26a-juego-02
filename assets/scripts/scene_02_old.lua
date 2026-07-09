
scene = {
  -- Tabla de imagenes y sprites
  sprites = {},

  -- Tabla con la info de las animaciones
  animations = {},

  -- Tabla de efectos de sonido
  sounds = {},

  -- Tabla de musica
  music = {},

  -- Tabla de fuentes
  fonts = {},

  -- Tabla de acciones y teclas
  keys = {},

  -- Tabla de acciones y botones de raton
  buttons = {
    [0] = 
    {name = "mouse_left_button", button = 1},
  },

  -- Tabla de mapa
  maps = {},

  -- Tabla de items
  items =  {},

  -- Tabla de ordenes
  orders = {},

  -- Tabla de entidades
  entities = {
    [0] =
    -- Player
    -- last on the list so it renders on top of all other entities
    {
      components = {
        player = {},
        tag = {
          tag = "player",
        },
        transform = {
          position = { x = 465.0, y = 200.0 },
          scale = { x = 1.0, y = 1.0 },
          rotation = 0.0,
        },
      },
    },
  },
}