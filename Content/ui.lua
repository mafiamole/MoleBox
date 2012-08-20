Player = {ScoreText = 0,CurrentScore=0}
Test = 0;
Computer = {ScoreText = 0,CurrentScore=0}
WindowDimensions = {}
WindowDimensions = {Window.Size()}
bgMusic = 0
function init()
  Player.ScoreText = Text.Create("0")
  Computer.ScoreText = Text.Create("0")
  
  print (WindowDimensions[1])
  
  setComputerTextLocation()
  bgMusic = Music.Load("mouthpop.wav")
  
  Music.Play(bgMusic)
  Music.SetLoop(bgMusic,true)
end

function setComputerTextLocation()
  computerTextSize = {Text.Size(Computer.ScoreText)}
  newSize = WindowDimensions[1] - computerTextSize[1]
  Text.SetPosition(Computer.ScoreText, newSize  ,0)

end

function update( elapsed, events,playerScore,computerScore )
  
  print (elapsed)
  print (events)
  print (computerScore)
  print (playerScore)
  print ("---------")
  if playerScore ~= Player.CurrentScore then
    Text.Modify(Player.ScoreText,playerScore)
    Player.CurrentScore = playerScore
  end
  
  if computerScore ~= Computer.CurrentScore then
    Text.Modify(Computer.ScoreText,computerScore)
    Computer.CurrentScore = computerScore
    setComputerTextLocation()
  end

end

function draw()
  
  Text.Draw(Player.ScoreText)
  Text.Draw(Computer.ScoreText)
  
end

 
