[Variables]
Battery_X =1221
;Left, Right or Center
Battery_Anchor=Right

[Metadata]
Name=Greenlean\\Battery
Author=reddit.com/u/khanhas
Description=Display battery level.

[BatteryAnchor]
Measure=String
String = #Battery_Anchor#
IfMatch = Center|center|Middle|middle
IfMatchAction = [!SetOption BatteryIcon X "(#Bar_OffsetX#+#*Battery_X*#-([*BatteryIcon:W*]+[*Battery:W*]+5)/2)"][!SetOption Battery X 5R]
IfMatch2 = Right|right
IfMatchAction2 = [!SetOption BatteryIcon StringAlign RightCenter][!SetOption Battery StringAlign RightCenter][!SetOption BatteryIcon X "([*Battery:X*]-[*BatteryIcon:W*]-5)"][!SetOption Battery X "(#Bar_OffsetX#+#*Battery_X*#)"]

[BatteryLevel]
Measure=Plugin
Plugin=PowerPlugin
PowerState=Percent

[BatteryShapeScale]
Measure=Calc
Formula=#Font_Size#/16

[BatteryIcon]
Meter=Shape
Shape=Rectangle 0,3,14,20,2 | StrokeWidth 2 | Stroke Color #Color_Scheme2# | Fill Color 0,0,0,1 
Shape2=Rectangle 3,0,8,3| StrokeWidth 0 | Fill Color #Color_Scheme2#
SHape3=Rectangle 3,20,(8),(-14*[BatteryLevel]/100) | StrokeWidth 0 | Fill Color #Color_Scheme3# 
FontSize=#Font_Size# 
AntiAlias=1
X=(#Bar_OffsetX#+#Battery_X#)
Y=(#Bar_OffsetY#+#Bar_Height#/2-[BatteryIcon:H]/2)
Group=Battery
DynamicVariables=1
TransformationMatrix=[BatteryShapeScale];0;0;[BatteryShapeScale];0;0

[Battery]
Meter=String
MeasureName=BatteryLevel
Postfix=%
FontFace=#Font_Face#
FontSize=#Font_Size#
FontColor=#Color_Scheme2#
AntiAlias=1
StringAlign=LeftCenter
X=5R
Y=(#Bar_OffsetY#+#Bar_Height#/2)
Group=Battery
DynamicVariables=1
