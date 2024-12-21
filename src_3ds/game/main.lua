scale = 0.3
dright = 0
dleft = 0
function love.load()
    local joysticks = love.joystick.getJoysticks()
    joystick = joysticks[1]
	dh = love.graphics.newImage("dining-hall.jpg")
	dh_right = love.graphics.newImage("dining-hall-right.jpg")
	sound = love.audio.newSource("AllNightAllDay.ogg", "stream")
	love.audio.play(sound)
	love.graphics.set3D(true)
	
end
function love.draw(screen)

	if screen == "top" then
	   love.graphics.draw(dh, dright, dleft,0,scale)
	end
	if screen == "right" then
	   love.graphics.draw(dh_right, dright, dleft,0,scale)
	end
	if screen == "left" then
	   love.graphics.draw(dh, dright, dleft,0,scale)
	end
	
	if screen == "bottom" then
	   return
	end
end
function love.update(dt)

   -- joystick code
   if not joystick then return end
   if joystick:isGamepadDown("b") then
       scale = scale - 0.002
   elseif joystick:isGamepadDown("x") then
       scale = scale + 0.002
   end
   if joystick:isGamepadDown("y") then
       scale = scale - 0.002
   elseif joystick:isGamepadDown("a") then
       scale = scale + 0.002
   end
   if joystick:isGamepadDown("dpleft") then
       dright = dright + 5
   elseif joystick:isGamepadDown("dpright") then
       dright = dright - 5
   end

   if joystick:isGamepadDown("dpup") then
       dleft = dleft + 5
   elseif joystick:isGamepadDown("dpdown") then
       dleft = dleft - 5
   end
end