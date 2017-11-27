# N-body simulation
Team: Younghoo Kim, Junwon You, Myoeugjin Nam

Due : 12/13
----------------------------------------------------------------------------------------------
# Nbody simulation 2017/11/27 변경 사항

## 1. as 커맨드
	set 생성 시, id 입력을 아무것도 안하면 널문자 id의 set이 생성됨 null인 경우 생성 방지해야함.

## 2. outset
	outset은 set이지만 set count에 포함시키지 않는듯하다. Set_of_set에서 제외시켜야할듯.
## 3. 소멸자
	가 호출되며 모두 삭제될 때 pcount, fcount는 0으로 만들어야함.

## 4. Gravity() 함수 구현
	버그 테스트는 안해봤음

# 수정해야할 점

## 1. 입력 범위 확대
	1.5 e+28 같은 지수적 표기도 입력할 수 있어야함.
	trans_input()함수 내에 e+을 구분하는 기능 추가해야함.

## 2. 접근제어지시자
	다 friend로 접근해서 private이 아무 의미가 없다.
	particle 클래스의 get,set메소드들 다 지워도 될 듯

## 3. 계산함수를 호출하는 Run() 을 UI에서 구현
-------------------------------------------------------------------

# Nbody simulation 2017/11/26 변경사항
UI-class branch	에 수정본 올렸음.

## 1. UI 구현 완료
-	입력된 문자형 숫자를 숫자 자료형으로 바꾸는 함수 trans_input() 구현
-	try, throw, catch문을 활용하여 예외처리기 만듦
-	Github 예시 참고하며 출력 문장 수정
## 2. particle id, set id 구조를 수정
	생성 시 자동으로 부여받는 줄 알았는데 force와 마찬가지로 사용자가 입력하는 id였음.
	id 와 setid를 쓰는 함수도 모두 수정 완료
# 추가해야 할 점

## 1. Gravity() 함수 구현
	준원 담당
	
## 2. 입력 범위 확대
	1.5 e+28 같은 지수적 표기도 입력할 수 있어야함.
	trans_input()함수 내에 e+을 구분하는 기능 추가해야함.
	
## 3. 커맨드 pt으로 현재 시간 출력하는 것 미구현
	무슨 뜻인지 해석해야함.



------------------------------------------------------------------------------------

# Nbody simulation 2017/11/22 변경사항

## 1. add_force(), delete_force() 구현 (Set_whole의 메소드)

## 2. showforce()함수 추가	(Set_particle의 메소드)

	printall에 force 목록도 출력되도록 수정

## 3. Set_particle의 소멸자 수정

	List나 fList가 가리키는 대상이 있을 때만 delete[] 하도록 수정했음.

## 4.(Set_particle 클래스)에 구조체 force_s, 구조체 포인터 fList, int형 num_f 변수 추가

	입력된 id 와 force들을 저장할 구조체 force_s 추가

	force_s를 저장할 배열 fList 추가

	fList의 길이를 나타낼 num_f 변수 추가

## 5. Set_particle에 getforce 추가

	fList에 있는 모든 힘들의 합을 double형 배열로 반환.




---------------------------------------------------------------------------------------------
# Nbody simulation 2017/11/21 변경사항

## 1.  double형 f  ->  double force_p[2]

	파티클 내의 f 변수를 set이 일괄적으로 주는 힘과 구분하기 위해 이름을 바꿈

## 2.  particle 멤버 변수로 char형 변수 pixation를 추가

	위치 고정 설정 구현을 위해 추가, on/off만 있으면 되므로 크기가 작은 char형 변수를 선택함


## 3.set과 particle 정보 출력 양식을 수정함

## 4.	Set_whole 클래스에 int형 변수 t_unit을 추가

	시뮬레이션 연산의 단위시간. 계산 오류 가능성을 줄이기 위해 int형으로 선언하고, 대신 단위를 작게 1ms정도로 생각할 것임.
	
## 5. (Set_particle 클래스)에 double**형 force_s, int형 num_f 변수 추가

	입력된 force들을 저장할 배열 force_s 추가

	force_s 배열의 길이를 나타낼 num_f 변수 추가

# 추가해야할 사항

## (Set_whole 클래스)

## 1. 시간에 대한 각입자의 정보를 저장할 2차원 배열 구조체 추가

	시뮬레이션 이전 상황으로 돌아가거나 시뮬레이션 도중의 결과를 보기 위해 필요하다.

	이 저장공간을 각 시뮬레이션 시마다 생성하고 저장해야 할 것 같다.

	만약 추가한다면 double형은 크기가 너무 크니까 float로 바꾸든, 위치만 저장하든 메모리 크기를 줄여야할 것이다. 

## 2. Calculate() 함수 구현 //위치와 속도 변화

	Calculate()함수 안에서는 Gravity() 함수를 호출할 것이다. 

	Calculate()에서는 모든 입자를 조회하여 Set에서 일괄적으로 주는 힘과 Gravity()의 결과로 바뀐 force_p의 값을 합하고 위치와 속도를 계산한다.

	fixation의 on/off 상태에 따라 각 입자의 위치와 속도를 변경한다.

## 3. char형 변수 gravity 추가, Gravity() 구현 // 힘 변화
	fixation과 같은 역할로, gravity가 1이면 Calculate()함수 안에서 Gravity()가 호출된다.

	gravity가 0이면 Gravity()함수 없이 계산한다.

	Gravity()함수는 입자 전체를 조회하여 각 입자마다 상호작용하는 힘을 해당 입자에 전달해준다.


	force_p는 이전 값과 무관하게 현재 입자들의 상대위치에 따라 정해지는 값이므로,

	gravity()함수 호출 시 모든 입자들의 force_p를 0으로 초기화하고 

	for문으로 실행하면서 입자간의 중력힘이 정해지면 각각 두 입자의 force_p에 더해지는 방식으로 할 것이다.

## 4. add_force(), delete_force()

	특정 set에 입력된 벡터의 force를 동적 생성/제거하는 함수()

## (UI 클래스)

## 1. 지속적으로 입력을 받아 이벤트를 반복하게 하는 run()함수 구현

	이로써 사용자는 main함수에서는 UI 객체를 하나 생성한뒤, run()함수만 호출함으로써 프로그램을 사용할 수 있음.

## 2. UI에서 받은 입력을 구분할 때, 다중 if문 대신 switch문으로 교체

	3~4개 이상의 분기로 갈라질 때는 switch문을 쓰는 것이 컴파일 상에서 더 효율적이라고 함.

## 3. 입력받은 string을 처리하는 함수들에 주석 필요

	무얼 하는 함수고 결과물을 어떻게 쓰는지 모르겠음
