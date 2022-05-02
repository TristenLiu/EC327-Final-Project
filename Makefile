OBJS	= Game.o main.o
SOURCE	= Game.cpp, main.cpp,
HEADER	= Game.h, Audio.hpp, Config.hpp, Main.hpp, Network.hpp, OpenGL.hpp, System.hpp, Window.hpp, Graphics.hpp, GpuPreference.hpp, Clipboard.hpp, Context.hpp, ContextSettings.hpp, Cursor.hpp, Event.hpp, Export.hpp, GIResource.hpp, Joystick.hpp, Keyboard.hpp, Mouse.hpp, Sensor.hpp, Touch.hpp, VideoMode.hpp, WindowHandle.hpp, WindowStyle.hpp, Clock.hpp, Err.hpp, FileInputStream.hpp, InputStream.hpp, Lock.hpp, MemoryInputStream.hpp, Mutex.hpp, NativeActivity.hpp, NonCopyable.hpp, Sleep.hpp, String.hpp, Thread.hpp, ThreadLocal.hpp, Time.hpp, Utf.hpp, Vector2.hpp, Vector3.hpp, Ftp.hpp, Http.hpp, IpAddress.hpp, Packet.hpp, Socket.hpp, SocketHandle.hpp, SocketSelector.hpp, TcpListener.hpp, TcpSocket.hpp, UdpSocket.hpp, BlendMode.hpp, CircleShape.hpp, Color.hpp, ConvexShape.hpp, Drawable.hpp, Font.hpp, Glsl.hpp, Glyph.hpp, Image.hpp, PrimitiveType.hpp, Rect.hpp, RectangleShape.hpp, RenderStates.hpp, RenderTarget.hpp, RenderTexture.hpp, RenderWindow.hpp, Shader.hpp, Shape.hpp, Sprite.hpp, Text.hpp, Texture.hpp, Transform.hpp, Transformable.hpp, Vertex.hpp, VertexArray.hpp, VertexBuffer.hpp, View.hpp, AIResource.hpp, Export.hpp, InputSoundFile.hpp, Listener.hpp, Music.hpp, OutputSoundFile.hpp, Sound.hpp, SoundBuffer.hpp, SoundBufferRecorder.hpp, SouldFileFactory.hpp, SoundFileFactory.inl, SoundFileReader.hpp, SoundFileWriter.hpp, SoundRecorder.hpp, SoundSource.hpp, SoundStream.hpp, flac.lib, freetype.lib, ogg.lib, openal32.lib, sfml-audio-d.lib, sfml-audio-s-d.lib, sfml-audio-s.lib, sfml-audio.lib, sfml-graphics-d.lib, sfml-graphics-s-d.lib, sfml-graphics-s.lib, sfml-graphics.lib, sfml-main-d.lib, sfml-main.lib, sfml-network-d.lib, sfml-network-s-d.lib, sfml-network-s.lib, sfml-network.lib, sfml-system-d.lib, sfml-system-s-d.lib, sfml-system-s.lib, sfml-system.lib, sfml-window-d.lib, sfml-window-s-d.lib, sfml-window-s.lib, sfml-window.lib, vorbis.lib, vorbisenc.lib, vorbisfile.lib, SFMLConfig.cmake, SFMLConfigDependencies.cmake, SFMLConfigVersion.cmake, SFMLSharedTargets-debug.cmake, SFMLSharedTargets-release.cmake, SFMLSharedTargets.cmake, SFMLStaticTargets-debug.cmake, SFMLSharedTargets-release.cmake, SFMLStaticTargets.cmake
OUT	= Game
CC	 = g++
FLAGS	 = -g -c -Wall
LFLAGS	 = 

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

Game.o: Game.cpp,
	$(CC) $(FLAGS) Game.cpp, -std=c++17

main.o: main.cpp,
	$(CC) $(FLAGS) main.cpp, -std=c++17

clean:
	rm $(OBJS) Game:wq 
