[Variables]
Power_X=1522
;Left, Right or Center
Power_Anchor=Right
Power_Width=(#Font_Size#*4)

[Metadata]
Name=Fedina\\Power
Author=reddit.com/u/khanhas
Description=Click to activate Power menu to Turn Off, Restart, Sleep or Log off.

[PowerAnchor]
Measure=String
String = #Power_Anchor#
IfMatch = Center|center|Middle|middle
IfMatchAction = [!SetOption PowerShape X "(#Bar_OffsetX#+#*Power_X*#-#Power_Width#/2)"]
IfMatch2 = Right|right
IfMatchAction2 = [!SetOption PowerShape X "(#Bar_OffsetX#+#*Power_X*#-#Power_Width#)"]

[PowerShape]
Meter=Shape
X=(#Bar_OffsetX#+#Power_X#)
Y=#Bar_OffsetY#
Shape=Rectangle 0,0,#Power_Width#,#Bar_Height# | StrokeWidth 0 | Extend Color
Color = Fill Color [ColorMeasureScript:GetColor('#Color_Scheme3#', '#Color_Scheme4#', 'side to middle', #Power_X#)]
DynamicVariables=1

[PowerButton]
Meter=String
Text=
FontFace=Material Icons
FontSize=(#Font_Size#*16/13)
FontColor=#Color_Scheme2#
AntiAlias=1
StringAlign=CenterCenter
X=(#Power_Width#/2)r
Y=(#Bar_OffsetY#+#Bar_Height#/2)
DynamicVariables=1
MouseOverAction=[!CommandMeasure AdditionalSkinActionTimer "Stop 1"]
MouseLeaveAction=[!CommandMeasure AdditionalSkinActionTimer "Execute 1"]
LeftMouseUpAction=[!SetOption #CURRENTSECTION# Text ][!UpdateMeter PowerButton][!Redraw][!WriteKeyValue Variables Curr_X (#Bar_OffsetX#+[PowerShape:X]+#Power_Width#/2+#CURRENTCONFIGX#) "#ROOTCONFIGPATH#\Themes\#Theme#\Additional_Comps_And_Scripts\PowerMenu.ini"][!WriteKeyValue Variables Curr_Y [SubSkinYPositionCalc] "#ROOTCONFIGPATH#\Themes\#Theme#\Additional_Comps_And_Scripts\PowerMenu.ini"][!WriteKeyValue Variables Dir [SubSkinDirectionCalc] "#ROOTCONFIGPATH#\Themes\#Theme#\Additional_Comps_And_Scripts\PowerMenu.ini"][!WriteKeyValue Variables Color [PowerColor] "#ROOTCONFIGPATH#\Themes\#Theme#\Additional_Comps_And_Scripts\PowerMenu.ini"][!ToggleConfig "#ROOTCONFIG#\Themes\#Theme#\Additional_Comps_And_Scripts" "PowerMenu.ini"]
