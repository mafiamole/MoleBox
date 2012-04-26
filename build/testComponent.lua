textures = {"test.png"}
function init()
  Sprites.Load("Test","ufpdfLogo.png")
  
end

function update(events)
  Sprite.SetPosition(100,245)
end

function draw()
  Sprites.Draw("Test")
end
