logoPosition = 1
direction    = 1
mySprite     = 0
sound	     = 0

function init()
  mySprite =  Sprites.Load("ufpdfLogo.png")
  sound = Sounds.Load("mouthpop.wav")
  Sprites.SetPosition(mySprite,10,10)
end

function update( events, elapsed )


   delta = 0.2 * direction * elapsed
   logoPosition = (logoPosition * direction) + delta
   
   print (logoPosition)
   
   if logoPosition > 15 then
     direction = -1
     Sounds.Play(sound)
   end
   if logoPosition < 1 then
     
     direction = 1
   end

  Sprites.Move(mySprite,logoPosition,logoPosition)
  
end

function draw()
  Sprites.Draw(mySprite)
end 