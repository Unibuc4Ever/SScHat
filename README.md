# SScHat -- Chatting app for SSH clients

This app uses the Telemetry client (imported as a submodule).
It's main utility is to be able to chat with multiple users all connected to the same SSH machine on the same user.

## Indented usage

### Wecome screen
```
*************************************************************
*                                                           *
*                                                           *
*                                                           *
*                                                           *
*           Please enter your display name:                 *
*                                                           *
*                      Theod..                              *
*                                                           *
*                                                           *
*                                                           *
*                                                           *
*                                                           *
*************************************************************
```

### Wecome screen
```
*************************************************************
*                                                           *
*                                                           *
*                                                           *
*                                                           *
*           Welcome Theodor! What channel do you want       *
*                        to join?                           *
*                                                           *
*                    /tmp/idk..                             *
*                                                           *
*                                                           *
*                                                           *
*                                                           *
*************************************************************
```

### Chat screen
```
*************************************************************
*  Alex:  Laurem sdgdfg   fdsfsdfdsfsd fsd dfds fds sdffsdf *
*         sdfsdfsdgfd                                       *
*  Matei: sdfdsfdsfsd fdsf                                  *
*  Alex: sdfsdfds fsd sdfsd                                 *
*  George: sdfdsfdsfsd fsdfsd fdsdfsdfsdf                   *
*                                                           *
*                                                           *
*                                                           *
*  _______________________________________________________  *
* |                                                       | *
* | Type your message here ...                            | *
* |_______________________________________________________| *
*************************************************************
```

## Ideeas
1. Use messages like the ones created by cowsay
 _________________________________________
/ asdsa dfdsf sdf sdfds fds sd            \
| sdfsdfksdfsdfdskfjdslfdsjkdslfjsdlfsdjf |
\ lskdfjsdlfdskjfklsd                     /
 -----------------------------------------
        \   ^__^
         \  (oo)\_______
            (__)\       )\/\
                ||----w |
                ||     ||


To know:
 * For compiling, we should use https://stackoverflow.com/questions/5430688/compiling-c-and-c-files-together-using-gcc.