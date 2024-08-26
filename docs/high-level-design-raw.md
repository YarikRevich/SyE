```plantuml
title

High-level design of "SyE"

end title

actor "Client"

component "Control plain" {
node "Init"
node "Handler"
node "Effects"
node "Scheduler"
note left: All the scheduled operations\n are executed in standalone threads
node "Signal"

cloud "Scheduler operations" {
node "Input" as SchedulerInput
node "Render"
node "Widget"
}

cloud "Effect operations" {
node "Input" as EffectInput
node "Window"
node "Loader"
node "Swap"
}
}

[Client] --> [Init]: " Perform application initialization"
[Init] --> [Signal]: " Register exit signal handler"
[Init] --> [Handler]: " Perform command"
[Handler] --> [Effects]: " Execute registered effects(init tasks)"
[Handler] --> [Scheduler]: " Schedule registered operations"
[Scheduler] --> [SchedulerInput]: " Execute input scanning operation"
[Scheduler] --> [Render]: " Execute rendering operation"
[Scheduler] --> [Widget]: " Execute widget processing operation"
[Effects] --> [EffectInput]: " Execute user provided input parsing"
[Effects] --> [Window]: " Perform terminal window initialization"
[Effects] --> [Loader]: " Perform loading of config and proper theme files(if so exist)"
[Effects] --> [Swap]: " Perform swap management initialization"
```