# splash-miyoo
Launches a (currently basic) splash screen with an icon provided as an arg

Will display a fullscreen splash with an image in the center supplied on the cmdline and a background colour of your choice

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

# Usage 
`/mnt/SDCARD/App/Spotify/splash /mnt/SDCARD/App/Spotify/logos/splash.png 240 240 240 &`

`./splash /path/to/img.png 90 90 90 &`

syntax: imagepath r g b 


# Example splash:
![Rom_Weasal_000](https://github.com/XK9274/splash-miyoo/assets/47260768/63b174cc-3762-4389-8194-d22ca46676f0)

![ncspot_001](https://github.com/XK9274/splash-miyoo/assets/47260768/5e864a10-556f-465c-9f40-4c230e52a33e)

![Syncthing_001](https://github.com/XK9274/splash-miyoo/assets/47260768/25cabb2e-bd89-4ff5-b083-e827ea1e9b61)

