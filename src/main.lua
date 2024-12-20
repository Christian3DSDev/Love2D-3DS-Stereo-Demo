scale = 0.415
dright = 0
dleft = 0
anaglyph = 0

function love.load()
    -- Load the right and left images
    rightImage = love.graphics.newImage("dining-hall-right.jpg")
    leftImage = love.graphics.newImage("dining-hall.jpg")
	sound = love.audio.newSource("AllNightAllDay.ogg", "stream")
	love.audio.play(sound)
end

function love.draw()
    -- Clear the screen
    if anaglyph == 0 then
   		love.graphics.setColor(255, 255, 255)
  	  	love.graphics.draw(leftImage, dright, dleft,0,scale)
	end
    if anaglyph == 1 then
   		love.graphics.setColor(255, 0, 0)
  	  	love.graphics.draw(leftImage, dright, dleft,0,scale)
   	 	love.graphics.setBlendMode("add")
   	 	love.graphics.setColor(0, 255, 255)
   	 	love.graphics.draw(rightImage, dright, dleft,0,scale)
	end

end
function love.update(dt)
   if love.keyboard.isDown("e") then
      scale = scale - 0.002
   end
   if love.keyboard.isDown("q") then
      scale = scale + 0.002
   end
   if love.keyboard.isDown("space") then
      scale = scale - 0.002
   end
   if love.keyboard.isDown("return") then
      scale = scale + 0.002
   end
   if love.keyboard.isDown("a") then
      dright = dright + 5
   end
   if love.keyboard.isDown("d") then
      dright = dright - 5
   end
   if love.keyboard.isDown("w") then
      dleft = dleft + 5
   end
   if love.keyboard.isDown("s") then
      dleft = dleft - 5
   end
   if love.keyboard.isDown("left") then
      dright = dright + 5
   end
   if love.keyboard.isDown("right") then
      dright = dright - 5
   end
   if love.keyboard.isDown("up") then
      dleft = dleft + 5
   end
   if love.keyboard.isDown("down") then
      dleft = dleft - 5
   end
   if love.keyboard.isDown("2") then
      anaglyph = 0
   end
   if love.keyboard.isDown("1") then
      anaglyph = 1
   end

end
