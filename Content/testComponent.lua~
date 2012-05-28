logoPosition = 0
direction    = 1
mySprite     = 0


function init()
  mySprite =  Sprites.Load("ufpdfLogo.png")
  --Sounds.Load("mouthpop.wav")
  Sprites.SetPosition(mySprite,10,10)
end

function update(events)
 --Sounds.Play("mouthpop.wav")-- o yea!
   delta = 0.2 * direction  
   logoPosition = (logoPosition * direction) + delta
   if logoPosition > 15 then
     direction = -1
     --Sounds.Play("mouthpop.wav")
   end
   if logoPosition < 1 then
     
     direction = 1
   end

  Sprites.Move(mySprite,logoPosition,logoPosition)
  
end

function draw()
  Sprites.Draw(mySprite)
end 