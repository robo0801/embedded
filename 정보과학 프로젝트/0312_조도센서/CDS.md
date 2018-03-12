# 1.CDS Sensor
- 광센서, 조도센서로 불리며 광전효과를 이요하여 빛의 양을 알아내는 장치로 빛 신호를 전기 신호로 바꾸어 줌.

![CDS_원리](https://raw.githubusercontent.com/robo0801/embedded/master/%EC%A0%95%EB%B3%B4%EA%B3%BC%ED%95%99%20%ED%94%84%EB%A1%9C%EC%A0%9D%ED%8A%B8/0312_%EC%A1%B0%EB%8F%84%EC%84%BC%EC%84%9C/pic/CDS_%EC%9B%90%EB%A6%AC.png){: width="20" height="80"}

- 광 다이오드: p형 반도체와 n형 반도체의 접합 구조로 되어 있으며, p-n 접합부에 빛을 비추면 광전 효과에 의해 전류가 흐른다. 
			이때 흐르는 전류는 빛의 세기에 비례함

![광다이오드](https://raw.githubusercontent.com/robo0801/embedded/master/%EC%A0%95%EB%B3%B4%EA%B3%BC%ED%95%99%20%ED%94%84%EB%A1%9C%EC%A0%9D%ED%8A%B8/0312_%EC%A1%B0%EB%8F%84%EC%84%BC%EC%84%9C/pic/%EA%B4%91%EB%8B%A4%EC%9D%B4%EC%98%A4%EB%93%9C.png)


# 2.CDS_LED_digital

## 회로도
- CDS는 연결방향에 관계없이 사용 가능하다.

![CDS_기본회로](https://raw.githubusercontent.com/robo0801/embedded/master/%EC%A0%95%EB%B3%B4%EA%B3%BC%ED%95%99%20%ED%94%84%EB%A1%9C%EC%A0%9D%ED%8A%B8/0312_%EC%A1%B0%EB%8F%84%EC%84%BC%EC%84%9C/pic/CDS_%EA%B8%B0%EB%B3%B8%ED%9A%8C%EB%A1%9C.png)

![CDS_LED_회로도](https://raw.githubusercontent.com/robo0801/embedded/master/%EC%A0%95%EB%B3%B4%EA%B3%BC%ED%95%99%20%ED%94%84%EB%A1%9C%EC%A0%9D%ED%8A%B8/0312_%EC%A1%B0%EB%8F%84%EC%84%BC%EC%84%9C/pic/CDS_LED_%ED%9A%8C%EB%A1%9C%EB%8F%84.png)
- 이 사진과 같이 회로를 구성하고 진행한다.


## sketch Code
- 코드는 폴더 내의 CDS_LED_digital_sketch 코드를 보세요.
- 이번은 13번에 LED를 연결합니다.


# 3.CDS_LED_analog

## 회로도
- digital 회로에서 LED에서 13번에서 10번으로 이동시킨다.

## sketch Code
- 코드는 폴더 내의 CDS_LED_analog_sketch 코드를 보세요.


# 완성 사진
![실제 완성 사진](https://raw.githubusercontent.com/robo0801/embedded/master/%EC%A0%95%EB%B3%B4%EA%B3%BC%ED%95%99%20%ED%94%84%EB%A1%9C%EC%A0%9D%ED%8A%B8/0312_%EC%A1%B0%EB%8F%84%EC%84%BC%EC%84%9C/pic/%EC%8B%A4%EC%A0%9C%20%EC%8B%A4%ED%96%89%20%EC%82%AC%EC%A7%84.jpg)