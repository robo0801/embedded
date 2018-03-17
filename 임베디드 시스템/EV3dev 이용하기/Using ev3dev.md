# ev3dev 사용하기


# 1. 준비물
- LEGO MINDSTORMS EV3
- A microSD or microSDHC card (2GB or larger). microSDXC is not supported on the EV3.
- 부팅 sd 카드 만드는데 필요한 컴퓨터
- sd 카드 connector


# 2. 설치하기

## 2.1 ev3dev image 파일을 다운 (Step 1)
- 아래 링크로 들어가서 각 플랫폼에 맞는 파일을 클릭
- ev3를 사용한다면 가운데 이미지 파일을 다운함
<http://www.ev3dev.org/docs/getting-started/>

## 2.2 SD 카드 굽기 (Step 2)
- 아래 링크를 들어가서 Etcher 다운함
<https://etcher.io/>
- 그 다음 Etcher를 설치함

- Etcher를 실행하고 이미지를 선택함
<img src="http://www.ev3dev.org/images/etcher/home.png">

- 다음 이미지를 입힐 SD 카드를 선택
- SD 카드는 비어 있어야 함
<img src="http://www.ev3dev.org/images/etcher/image-selected.png">

- Flash 누름 (시간이 오래 걸림)
<img src="http://www.ev3dev.org/images/etcher/drive-selected.png">

- 끝난 후 포맷 시키지 않고 메모리를 컴퓨터와 분리함


# 3. Boot ev3dev (step 4)
- EV3에서 리눅스를 사용하기 위해 전까지 부팅 SD카드를 만들었습니다.
- SD카드를 EV3 옆쪽에 넣어줍니다. 그 다음 로봇의 전원을 켜줍니다.
<img src="http://www.ev3dev.org/images/brickman/main-menu.png">
- 끄는 방법은 좌측 상단 버튼을 누르면 다음과 같은 그림이 나옵니다.
- 그 다음 power off에서 버튼을 누르면 됩니다.
<img src="http://www.ev3dev.org/images/brickman/shutdown-menu.png">


# 4. 네트워크 연결(와이파이를 잡아 연결함) (Step 5)
- 다음 링크 참고
<http://www.ev3dev.org/docs/networking/>

## 4.1 Wi-Fi dongle 사용
- 와이파이 동글은 와이파이를 잡을 수 있게 신호를 잡는 장치이다.
- ev3에서 호환되는 제품은 다음 3가지 이다.
	- NetGear WNA1100 Wireless-N 150 (officially supported by LEGO’s software)
	- Edimax EW-7811Un 802.11n Wireless Adapter (officially supported by LEGO’s software)
	- EP-N8508GS 150Mbps Mini Wireless 802.11N USB Adapter (not officially supported by LEGO, but also works)

## 4.2 USB 포트를 이용한 연결
<http://www.ev3dev.org/docs/tutorials/connecting-to-the-internet-via-usb/>

## 4.3 Bluetooth를 사용한 연결
<http://www.ev3dev.org/docs/tutorials/connecting-to-the-internet-via-bluetooth/>


# 5. SSH를 통한 EV3와 연결(Step 6)
- PuTTY라는 프로그램을 다운로드 한다. 그리고 열어주게 되면 다음 사진과 같이 나오게 된다.
<http://www.ev3dev.org/images/windows/10/putty-configuration-ev3dev.png>
- 사진에 나온대로 입력해주거나 ev3dev에 ev3에 뜬 ip 주소를 입력해도 된다.
- 연결을 성공하면 다음과 같은 화면이 나온다.
<http://www.ev3dev.org/images/windows/10/putty-robot-at-ev3dev.png>

- fortune 이라고 입력해 본다.


# 6. 언어를 선택하여 코드를 작성 (Step 7)
- 사용 가능한 언어
```
python, JavaScript, Java, Go, C++, C
```
<http://www.ev3dev.org/docs/programming-languages/>




