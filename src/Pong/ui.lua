Player = {ScoreText = 0,CurrentScore=0}
Test = 0;
Computer = {ScoreText = 0,CurrentScore=0}
WindowDimensions =  {}
WindowDimensions = {Window.Size()}

function init()
  Player.ScoreText = Text.Create("0")
  Computer.ScoreText = Text.Create("0")
  Test = Music.Load("test.ogg")
  Music.Play(Test)
  setComputerTextLocation()
end

function setComputerTextLocation() 
  computerTextSize = {Text.Size(Computer.ScoreText)}
  newSize = WindowDimensions[1] - computerTextSize[1]
  Text.SetPosition(Computer.ScoreText, newSize ,0)

end

function update( events, elasped, playerScore, computerScore )

  if  playerScore ~= Player.CurrentScore then
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

