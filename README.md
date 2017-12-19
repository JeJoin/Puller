the puller, it can pull the rtmp stream





ffmpeg.exe -f rawvideo -pix_fmt yuv420p -s:v 640*480 -i yuv640_480.yuv -c:v libx264 -f rawvideo output_h264.h264