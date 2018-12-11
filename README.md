# sudoku
리눅스 기반 스도쿠 게임 구현

주된 소스 : gosudoku.c(정답 알고리즘), input_outpu.c(게임의 입출력), sudoku.c(실행파일 진행)

기능
	스도쿠의 region과 가로세로에 입력하는 숫자와 중복되는 숫자 있는지 확인하는 기능(정답 알고리즘 : isOKUD, isOKLR, isOKregion, 사용자 입력 : checkHorizontal, checkVertical, checkSquare)
	스도쿠의 판이 주어지면 backTracking 알고리즘을 사용하여 정답을 구하는 기능(정답 알고리즘 : solveSudoku, checkNext)
	스도쿠 판에 사용자의 입력을 받아 게임이 진행될 수 있도록 하는 기능(사용자 입력 : getNumber)

-비기능
	난이도별 스도쿠 판 텍스트 파일을 읽어오는 기능(사용자 입력 : get_data, putNum2Array)
	0, 1~9 의 범위를 벗어나는 숫자 입력시 경고메세지 출력 기능(사용자 입력 : checkRange)
	스도쿠 중 가로, 세로, region의 이미 있는 값과 중복되는 숫자를 넣었을 때, 오류메세지 출력과 함께 중복되는 숫자의 위치를 빨간색으로 출력하는 기능(사용자 입력 : checkHorizontal, checkVertical, checkSquare, showSolution)
	원래 스도쿠판에 있던 숫자 자리에 입력시 경고 메시지 출력 기능(사용자 입력 : getNumber)
	0을 입력하도록 하여 사용자가 입력한 숫자를 지우는 기능(사용자 입력 : getNumber)
	스도쿠 성공시 성공 메시지 및 답안지 출력 기능(사용자 입력 : isItCorrect, full)


 gosudoku.c에서는 backTracking 알고리즘을 구현하여 정답을 찾아내는 것을 수행하였습니다. 이를 통해서 게임을 운용할 때, 답안을 바탕으로 사용자의 입력을 제어할 수 있었습니다. 또한, makefile을 작성함으로써 라이브러리, 오브젝트파일, 실행파일 등을 재귀적으로 관리할 수 있도록 하였습니다.
 input_outpu.c에서는 사용자의 입력에 따라 스도쿠 게임을 진행될 수 있도록 구현하는 과정을 수행하였습니다. 사용자의 입력에서 오류가 발생했는지를 검사하고, 오류가 발생했다면 이를 스도쿠판에 출력함으로써 정답에 근접해질 수 있도록 하였습니다. 또한, 알고리즘 파일과 사용자 입출력 파일이 sudoku.c 라는 파일에서 main을 두고 스도쿠 게임이 진행되도록 두 파일의 함수들을 배치하였습니다.
 
