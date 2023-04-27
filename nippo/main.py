import mouse,time,serial,vlc
import random

musicLibrary=["./indian.mp3",
              "tralala.mp3",
              "./ppp.mp3"]

mouse.FAILSAFE=False
ser=serial.Serial("COM3",9600)
instance=vlc.Instance()
player=instance.media_player_new()

counter=0

while True:
    media=instance.media_new(musicLibrary[random.randint(0,2)])
    media.add_option('start-time=0')
    media.add_option('stop-time=1')
    read=str(ser.readline().decode('ascii'))
    print(read)
    (x,y,z)=read.split()
    (X,Y)=mouse.get_position()
    (x,y)=(int(x),int(y))
    mouse.move(X+x,Y+y)

    if '1' in z:
        if counter==0:
            mouse.click()
            counter+=1
        else:
            mouse.click()
            player.audio_set_volume(100)
            player.set_media(media)
            player.play()