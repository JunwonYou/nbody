# N-body simulation
Team: Younghoo Kim, Junwon You, Myoeugjin Nam

Due : 12/13
----------------------------------------------------------------------------------------------
# Nbody simulation 2017/11/21 변경사항

1.  double형 f  ->  double force_p[2]
	파티클 내의 f 변수를 set이 일괄적으로 주는 힘과 구분하기 위해 이름을 바꿈

2.  particle 멤버 변수로 char형 변수 pixation를 추가
	위치 고정 설정 구현을 위해 추가, on/off만 있으면 되므로 크기가 작은 char형 변수를 선택함

3.	set과 particle 정보 출력 양식을 수정함

4.	Set_whole 클래스에 int형 변수 t_unit을 추가
	시뮬레이션 연산의 단위시간. 계산 오류 가능성을 줄이기 위해 int형으로 선언하고, 대신 단위를 작게 1ms정도로 생각할 것임.
	
5. (Set_particle 클래스)에 double**형 force_s, int형 num_f 변수 추가
	입력된 force들을 저장할 배열 force_s 추가
	force_s 배열의 길이를 나타낼 num_f 변수 추가

# 추가해야할 사항

(Set_whole 클래스)

1. 시간에 대한 각입자의 정보를 저장할 2차원 배열 구조체 추가
	시뮬레이션 이전 상황으로 돌아가거나 시뮬레이션 도중의 결과를 보기 위해 필요하다.
	이 저장공간을 각 시뮬레이션 시마다 생성하고 저장해야 할 것 같다.
	만약 추가한다면 double형은 크기가 너무 크니까 float로 바꾸든, 위치만 저장하든 메모리 크기를 줄여야할 것이다. 

2. Calculate() 함수 구현 //위치와 속도 변화
	Calculate()함수 안에서는 Gravity() 함수를 호출할 것이다. 
	Calculate()에서는 모든 입자를 조회하여 Set에서 일괄적으로 주는 힘과 Gravity()의 결과로 바뀐 force_p의 값을 합하고 위치와 속도를 계산한다.
	fixation의 on/off 상태에 따라 각 입자의 위치와 속도를 변경한다.

3. Gravity() 구현 // 힘 변화
	

4. add_force(), delete_force()
	특정 set에 입력된 벡터의 force를 동적 생성/제거하는 함수()

(UI 클래스)

1. 지속적으로 입력을 받아 이벤트를 반복하게 하는 run()함수 구현
	이로써 사용자는 main함수에서는 UI 객체를 하나 생성한뒤, run()함수만 호출함으로써 프로그램을 사용할 수 있음.

2. UI에서 받은 입력을 구분할 때, 다중 if문 대신 switch문으로 교체
	3~4개 이상의 분기로 갈라질 때는 switch문을 쓰는 것이 컴파일 상에서 더 효율적이라고 함.

3. 입력받은 string을 처리하는 함수들에 주석 필요
	무얼 하는 함수고 결과물을 어떻게 쓰는지 모르겠음
