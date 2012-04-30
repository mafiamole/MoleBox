logoPosition = 0
direction    = 1
function init()
  Sprites.Load("Test","ufpdfLogo.png")
  Sounds.Load("mouthpop.wav")
  Sprites.Move("Test",10,10)
end

function update(events)
 --Sprite.SetPosition(100,245)
 --Sounds.Play("mouthpop.wav")-- o yea!
  if logoPosition > 15 then
    direction = -1
    io.write("going back")
  end
  if logoPosition < 0 then
    direction = 1
  end
    
  logoPosition = (logoPosition + 0.2) * direction
  
  io.write(logoPosition)
  io.write("\n")
  Sprites.Move("Test",logoPosition,logoPosition)
end

function draw()
  Sprites.Draw("Test")
end 