# splash-miyoo
Launches a splash screen with an icon provided as an arg

Will display a fullscreen splash

# Issues
Will only display when sent a sigint.. not sure if it's mainui related

Example to start the splash:

```/mnt/SDCARD/App/Spotify/splash /mnt/SDCARD/App/Spotify/logos/splash.png 80 80 80 &
splash_pid=$!
sleep 1
kill -2 $splash_pid
sleep 2
killall -9 splash
```

# Usage 
`/mnt/SDCARD/App/Spotify/splash /mnt/SDCARD/App/Spotify/logos/splash.png &`

`./splash /path/to/img.png 90 90 90 &`

syntax: imagepath r g b 


