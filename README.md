# splash-miyoo
Launches a splash screen with an icon provided as an arg

Will display a fullscreen splash

# Issues
Will only display when sent a sigint.. not sure if it's mainui related

Example to start the splash:

```
/mnt/SDCARD/App/Spotify/splash /mnt/SDCARD/App/Spotify/logos/splash.png 80 80 80 &
splash_pid=$!
sleep 1
kill -2 $splash_pid
sleep 2
killall -9 splash
```

# Example splash:

![ncspot_001](https://github.com/XK9274/splash-miyoo/assets/47260768/5e864a10-556f-465c-9f40-4c230e52a33e)

# Usage 
`/mnt/SDCARD/App/Spotify/splash /mnt/SDCARD/App/Spotify/logos/splash.png &`

`./splash /path/to/img.png 90 90 90 &`

syntax: imagepath r g b 


