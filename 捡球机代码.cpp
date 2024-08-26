control.c
#include "control.h"
#include "oled.h"
#include "sys.h"

extern u8 PriFlag;
extern u8 ChangeFlag;
/*
函数功能：判断需要向左还是向右移动
返回值：1 向左
	   2 向右
	   3 不移动
*/
u8 TurnRightOrLeft(int x)
{
	if((x<160)&&(160-x>=10))
		return 1;
	else if((x>160)&&(x-160>=10))
		return 2;
	else if(abs(160-x)<10)
		return 3;
}
/*
函数功能：判断需要停止
*/
u8 TimeStop(int y)
{
	if(y>=200) return 1;
	else return 2;
}
/**************************************************************************
函数功能：定时中断函数 所有的控制代码都在这里面
**************************************************************************/
int count=0;
int count_1=0,count_2=0,count_3=0;
u8 DirectionFlag=0;
u8 MoveXCenter=0;//移动到了视野中心
u8 GoEhead=0;//前进
u8 stop_flag=0;
u8 step=0;
u8 man_flag=0;//满了
u8 center=0;
extern u8 error_flag;
void StepFunc()
{
	switch(step)
	{
		case 0:
			if((MoveXCenter==0)&&(ChangeFlag==0))
			{
				count++;
				if(count<=300)
				{
					turn(right,0.9);
					printf("StepFunc 111\n");
				}
				if(count>300)
				{
					turn(left,0.9);
					printf("StepFunc 222\n");
				}
				if(count==600)count=0;
			}

			if(MoveXCenter==1&&(ChangeFlag==0))
			{
				step++;
				MoveXCenter=0;
			}
			break;

		case 1:
			if((MoveXCenter==1)&&(ChangeFlag==0))
			{
				if(DirectionFlag==1)
				{
					turn(left,0.7);
					printf("center_turnleft\n");
					DirectionFlag=0;
				}
				else if(DirectionFlag==2)
				{
					turn(right,0.7);
					printf("center_turnright\n");
					DirectionFlag=0;
				}
				else if(DirectionFlag==3)
				{
					printf("carStop\n");
					DirectionFlag=0;
					step++;
				}
				MoveXCenter=0;
			}
		break;

		case 2:
			if(ChangeFlag==0)
			{
				if(stop_flag==2)
				{
					move(qian,0.6);
					printf("go_1\n");
					MoveXCenter=0;
					stop_flag=0;
				}
				if(stop_flag==1)
				{
					//stop_flag=0;
					MoveXCenter=0;
					count++;
					printf("go_2\n");
					if(count==800)
					{
						count=0;
						MoveXCenter=0;
						car_stop();
						step=0;
					}
				}
			}
			break;

		default:
			break;
	}

}
int TIM2_IRQHandler(void)
{

	if (TIM_GetITStatus(TIM2, TIM_IT_Update) != RESET) //检查指定的TIM中断发生与否:TIM 中断源
	{
		TIM_ClearITPendingBit(TIM2, TIM_IT_Update  );  //清除TIMx的中断待处理位:TIM 中断源

		if(delay_flag==1)
			if(++delay_50==5)
				delay_50=0,delay_flag=0;  //给主函数提供50ms的精准延时

		if(start_flag==1)
		{
			DirectionFlag=TurnRightOrLeft(re_x);
			stop_flag=TimeStop(re_y);
			start_flag=0;
			MoveXCenter=1;
		}

		if(M1==1)
		{
			man_flag=0;
			HideMove();
			BEEP(0);
		}

		if(M1==0)
		{
			man_flag=1;
			PriFlag=0;
			ChangeFlag=0;
			car_stop();
		}

		if((HL==1)&&(HR==1)&&(TR==1)&&(TL==1)&&(ChangeFlag==0)&&(man_flag==0))
			StepFunc();

		switch(PriFlag) //自动巡航
		{
			case 1:
				count++;
				printf("PriFlag 111\n");
				if(count<=100)
				move(hou,0.7);
				if(count>100)
				{
					turn(right,0.8);
					if(count==200)
					{
						count=0;
						ChangeFlag=0;
						PriFlag=0;
					}
				}
			break;

			case 2:
				printf("PriFlag case_2\n");
					count++;
				if(count<=100)move(hou,0.7);
				if(count>100)
				{
					turn(left,0.8);
					if(count==200)
					{
						printf("PriFlag 222\n");
						count=0;
						ChangeFlag=0;
						PriFlag=0;
					}
				}
			break;

			case 3:
				printf("PriFlag case_3\n");
					count++;
				if(count<=100)move(qian,0.8);
				if(count==120)
				{
					count=0;
					ChangeFlag=0;
					PriFlag=0;
				}
			break;

			case 4:
				printf("PriFlag case_4\n");
				count++;
				if(count<=100)move(qian,0.8);
				if(count==120)
				{
					count=0;
					ChangeFlag=0;
					PriFlag=0;
				}
			break;

			case 5:
				printf("PriFlag case_5\n");
				count++;
				if(count<=50)move(hou,0.6);
				if(count>50)
				{
					turn(right,0.8);
					printf("PriFlag 333\n");
					if(count==100)
					{
						count=0;
						ChangeFlag=0;
						PriFlag=0;
					}
				}
			break;

			default:
			break;
		}
	}
	return 0;
}


#include "DataScope_DP.h"
unsigned char DataScope_OutPut_Buffer[42] = {0};	   //串口发送缓冲区


//函数说明：将单精度浮点数据转成4字节数据并存入指定地址
//附加说明：用户无需直接操作此函数
//target:目标单精度数据
//buf:待写入数组
//beg:指定从数组第几个元素开始写入
//函数无返回
void Float2Byte(float *target,unsigned char *buf,unsigned char beg){
    unsigned char *point;
    point = (unsigned char*)target;	  //得到float的地址
    buf[beg]   = point[0];
    buf[beg+1] = point[1];
    buf[beg+2] = point[2];
    buf[beg+3] = point[3];
}


//函数说明：将待发送通道的单精度浮点数据写入发送缓冲区
//Data：通道数据
//Channel：选择通道（1-10）
//函数无返回
void DataScope_Get_Channel_Data(float Data,unsigned char Channel){
	if ( (Channel > 10) || (Channel == 0) ) return;  //通道个数大于10或等于0，直接跳出，不执行函数
	else
	{
		switch (Channel)
		{
			case 1:  Float2Byte(&Data,DataScope_OutPut_Buffer,1); break;
			case 2:  Float2Byte(&Data,DataScope_OutPut_Buffer,5); break;
			case 3:  Float2Byte(&Data,DataScope_OutPut_Buffer,9); break;
			case 4:  Float2Byte(&Data,DataScope_OutPut_Buffer,13); break;
			case 5:  Float2Byte(&Data,DataScope_OutPut_Buffer,17); break;
			case 6:  Float2Byte(&Data,DataScope_OutPut_Buffer,21); break;
			case 7:  Float2Byte(&Data,DataScope_OutPut_Buffer,25); break;
			case 8:  Float2Byte(&Data,DataScope_OutPut_Buffer,29); break;
			case 9:  Float2Byte(&Data,DataScope_OutPut_Buffer,33); break;
			case 10: Float2Byte(&Data,DataScope_OutPut_Buffer,37); break;
		}
	}
}


//函数说明：生成 DataScopeV1.0 能正确识别的帧格式
//Channel_Number，需要发送的通道个数
//返回发送缓冲区数据个数
//返回0表示帧格式生成失败
unsigned char DataScope_Data_Generate(unsigned char Channel_Number){
	if ((Channel_Number>10)||(Channel_Number==0))return 0;  //通道个数大于10或等于0，直接跳出，不执行函数
	else{
		DataScope_OutPut_Buffer[0] = '$';  //帧头
		switch(Channel_Number){
			case 1:   DataScope_OutPut_Buffer[5]  =  5; return  6;
			case 2:   DataScope_OutPut_Buffer[9]  =  9; return 10;
			case 3:   DataScope_OutPut_Buffer[13] = 13; return 14;
			case 4:   DataScope_OutPut_Buffer[17] = 17; return 18;
			case 5:   DataScope_OutPut_Buffer[21] = 21; return 22;
			case 6:   DataScope_OutPut_Buffer[25] = 25; return 26;
			case 7:   DataScope_OutPut_Buffer[29] = 29; return 30;
			case 8:   DataScope_OutPut_Buffer[33] = 33; return 34;
			case 9:   DataScope_OutPut_Buffer[37] = 37; return 38;
			case 10:  DataScope_OutPut_Buffer[41] = 41; return 42;
		}
  	}
	return 0;
}

Show.c
#include "show.h"

unsigned char i;          //计数变量
unsigned char Send_Count; //串口需要发送的数据个数
float Vol;

void oled_show(void){
	// OLED_ShowString(0,0,"K");
	// OLED_ShowNumber(5,0,PS2_KEY,2,12);

	//OLED_ShowString(0,0,"S:");
	OLED_ShowNumber(0,0,Speed,2,12);

	OLED_ShowString(37,0,".");
	OLED_ShowString(57,0,"V");
	OLED_ShowNumber(25,0,Voltage/100,2,12);
	OLED_ShowNumber(44,0,Voltage%100,2,12);
		if(Voltage%100<10) 	OLED_ShowNumber(31,0,0,2,12);
			if(Flag_Way==1) OLED_ShowString(70,0,"XYZ");  //坐标控制
	else if(Flag_Way==0)	OLED_ShowString(70,0,"ABC");   //单独控制
//=============显示电机A的状态=======================//
	if(Target1<0)		   // OLED_ShowString(00,10,"-"),
		OLED_ShowNumber(0,10,-Target1,4,12);
	else                 //	OLED_ShowString(0,10,"+"),
		OLED_ShowNumber(0,10, Target1,4,12);

	if( Position1<0)		 // OLED_ShowString(28,10,"-"),
		OLED_ShowNumber(30,10,-Position1,4,12);
	else                 	//OLED_ShowString(28,10,"+"),
		OLED_ShowNumber(30,10, Position1,4,12);

	//=============显示电机B的状态=======================//
	if( Target2<0)		//  OLED_ShowString(00,20,"-"),
		OLED_ShowNumber(0,20,-Target2,4,12);
	else                // 	OLED_ShowString(0,20,"+"),
		OLED_ShowNumber(0,20, Target2,4,12);

	if( Position2<0)		  //OLED_ShowString(60,20,"-"),
		OLED_ShowNumber(30,20,-Position2,4,12);
	else                 //	OLED_ShowString(60,20,"+"),
		OLED_ShowNumber(30,20, Position2,4,12);

	//=============显示电机C的状态=======================//
		if( Target3<0)		//  OLED_ShowString(00,30,"-"),
		OLED_ShowNumber(0,30,-Target3,4,12);
	else                // 	OLED_ShowString(0,30,"+"),
		OLED_ShowNumber(0,30, Target3,4,12);

	if( Position3<0)		 // OLED_ShowString(60,30,"-"),
		OLED_ShowNumber(30,30,-Position3,4,12);
	else                 //	OLED_ShowString(60,30,"+"),
		OLED_ShowNumber(30,30, Position3,4,12);

	//=============显示电机D的状态=======================//
		if( Target4<0)	  	//OLED_ShowString(00,40,"-"),
		OLED_ShowNumber(0,40,-Target4,4,12);
	else                 	//OLED_ShowString(0,40,"+"),
		OLED_ShowNumber(0,40, Target4,4,12);

	if( Position4<0)		 // OLED_ShowString(60,40,"-"),
		OLED_ShowNumber(30,40,-Position4,4,12);
	else                 //	OLED_ShowString(60,40,"+"),
		OLED_ShowNumber(30,40, Position4,4,12);

		//=============显示电机D的状态=======================//
	if( Target5<0)	    	//OLED_ShowString(00,50,"-"),
		OLED_ShowNumber(0,50,-Target5,4,12);
	else                // 	OLED_ShowString(0,50,"+"),
		OLED_ShowNumber(0,50, Target5,4,12);

	if( Position5<0)		 // OLED_ShowString(60,50,"-"),
		OLED_ShowNumber(30,50,-Position5,4,12);
	else                // 	OLED_ShowString(60,50,"+"),
		OLED_ShowNumber(30,50, Position5,4,12);


	OLED_ShowString(60,10,"X:");
	OLED_ShowString(60,24,"Y:");
	OLED_ShowString(60,38,"Z:");
	OLED_ShowString(60,52,"a:");
							//Show_float_num(88,24,TargetY,3,12);
	show_float_num1(78,24,TargetY);
	show_float_num1(78,38,TargetZ);
							show_float_num1(78,10, TargetX);
	show_float_num1(78,52, Target_Alpha);

	//=============刷新=======================//
	OLED_Refresh_Gram();
}
/**************************************************************************
函数功能：向APP发送数据
入口参数：无
返回  值：无

**************************************************************************/
void APP_Show(void){
	static u8 flag;
	int app_2,app_3,app_4;
	app_4=(Voltage-1110)*2/3;
	if(app_4<0)app_4=0;if(app_4>100)app_4=100;   //对电压数据进行处理
	//    app_3=Moto1/50; if(app_3<0)app_3=-app_3;			                           //对编码器数据就行数据处理便于图形化
	//		app_2=Moto2/50;  if(app_2<0)app_2=-app_2;
	flag=!flag;
	if(PID_Send==1){//发送PID参数
		printf("{C%d:%d:%d:%d:%d:%d:%d:%d:%d}$",(int)(Balance_Kp*100),(int)(Balance_Kd*100),(int)(Velocity_Kp*100),(int)(Velocity_Ki*100),0,0,0,0,0);//打印到APP上面
		PID_Send=0;
	}
	else if(flag==0)//
		printf("{A%d:%d:%d:%d}$",(u8)app_2,(u8)app_3,(u8)app_4,0);//打印到APP上面
	else
		printf("{B%d:%d:%d:%d:%d}$",(int)Position1,(int)Position2,(int)Position3,(int)Position4,(int)Position5);//打印到APP上面 显示波形
}
/**************************************************************************
函数功能：虚拟示波器往上位机发送数据 关闭显示屏

**************************************************************************/
void DataScope(void){
    Vol=(float)Voltage/100;
	DataScope_Get_Channel_Data(Position1, 1 );   //显示角度 单位：度（°）
	DataScope_Get_Channel_Data(Position2, 2 );   //显示超声波测量的距离 单位：CM
	DataScope_Get_Channel_Data(Position3, 3 );   //显示电池电压 单位：V
	DataScope_Get_Channel_Data(Position4, 4 );
	DataScope_Get_Channel_Data(Position5, 5 ); //用您要显示的数据替换0就行了

	Send_Count = DataScope_Data_Generate(5);
	for( i = 0 ; i < Send_Count; i++){
		while((USART1->SR&0X40)==0);
		USART1->DR = DataScope_OutPut_Buffer[i];
	}
}


#include "adc.h"

/**************************************************************************
函数功能：ACD初始化电池电压检测
**************************************************************************/
void  Adc_Init(void){
 	ADC_InitTypeDef ADC_InitStructure;
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA |RCC_APB2Periph_ADC1	, ENABLE );	  //使能ADC1通道时钟
	RCC_ADCCLKConfig(RCC_PCLK2_Div6);   //设置ADC分频因子6 72M/6=12,ADC最大时间不能超过14M
	//设置模拟通道输入引脚
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;		//模拟输入引脚
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	ADC_DeInit(ADC1);  //复位ADC1,将外设 ADC1 的全部寄存器重设为缺省值
	ADC_InitStructure.ADC_Mode = ADC_Mode_Independent;	//ADC工作模式:ADC1和ADC2工作在独立模式
	ADC_InitStructure.ADC_ScanConvMode = DISABLE;	//模数转换工作在单通道模式
	ADC_InitStructure.ADC_ContinuousConvMode = DISABLE;	//模数转换工作在单次转换模式
	ADC_InitStructure.ADC_ExternalTrigConv = ADC_ExternalTrigConv_None;	//转换由软件而不是外部触发启动
	ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;	//ADC数据右对齐
	ADC_InitStructure.ADC_NbrOfChannel = 1;	//顺序进行规则转换的ADC通道的数目
	ADC_Init(ADC1, &ADC_InitStructure);	//根据ADC_InitStruct中指定的参数初始化外设ADCx的寄存器
	ADC_Cmd(ADC1, ENABLE);	//使能指定的ADC1
	ADC_ResetCalibration(ADC1);	//使能复位校准
	while(ADC_GetResetCalibrationStatus(ADC1));	//等待复位校准结束
	ADC_StartCalibration(ADC1);	 //开启AD校准
	while(ADC_GetCalibrationStatus(ADC1));	 //等待校准结束
	ADC_SoftwareStartConvCmd(ADC1,ENABLE);
}

/**************************************************************************
函数功能：AD采样
入口参数：ADC1 的通道
返回  值：AD转换结果
**************************************************************************/
u16 Get_Adc(u8 ch){
	//设置指定ADC的规则组通道，一个序列，采样时间
	ADC_RegularChannelConfig(ADC1, ch, 1, ADC_SampleTime_239Cycles5 );	//ADC1,ADC通道,采样时间为239.5周期
	ADC_SoftwareStartConvCmd(ADC1, ENABLE);		//使能指定的ADC1的软件转换启动功能
	while(!ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC ));//等待转换结束
	return ADC_GetConversionValue(ADC1);	//返回最近一次ADC1规则组的转换结果
}


/**************************************************************************
函数功能：读取电池电压
入口参数：无
返回  值：电池电压 单位MV
**************************************************************************/
int Get_battery_volt(void){
	int Volt;//电池电压
	Volt=Get_Adc(Battery_Ch)*3300/4096;	//电阻分压，具体根据原理图简单分析可以得到
	//	if(Volt>1260)Volt=1260;

	return Volt;
}



#include "DataScope_DP.h"

unsigned char DataScope_OutPut_Buffer[42] = {0};	   //串口发送缓冲区


//函数说明：将单精度浮点数据转成4字节数据并存入指定地址
//附加说明：用户无需直接操作此函数
//target:目标单精度数据
//buf:待写入数组
//beg:指定从数组第几个元素开始写入
//函数无返回
void Float2Byte(float *target,unsigned char *buf,unsigned char beg){
    unsigned char *point;
    point = (unsigned char*)target;	  //得到float的地址
    buf[beg]   = point[0];
    buf[beg+1] = point[1];
    buf[beg+2] = point[2];
    buf[beg+3] = point[3];
}


//函数说明：将待发送通道的单精度浮点数据写入发送缓冲区
//Data：通道数据
//Channel：选择通道（1-10）
//函数无返回
void DataScope_Get_Channel_Data(float Data,unsigned char Channel){
	if ( (Channel > 10) || (Channel == 0) ) return;  //通道个数大于10或等于0，直接跳出，不执行函数
	else{
		switch (Channel){
			case 1:  Float2Byte(&Data,DataScope_OutPut_Buffer,1); break;
			case 2:  Float2Byte(&Data,DataScope_OutPut_Buffer,5); break;
			case 3:  Float2Byte(&Data,DataScope_OutPut_Buffer,9); break;
			case 4:  Float2Byte(&Data,DataScope_OutPut_Buffer,13); break;
			case 5:  Float2Byte(&Data,DataScope_OutPut_Buffer,17); break;
			case 6:  Float2Byte(&Data,DataScope_OutPut_Buffer,21); break;
			case 7:  Float2Byte(&Data,DataScope_OutPut_Buffer,25); break;
			case 8:  Float2Byte(&Data,DataScope_OutPut_Buffer,29); break;
			case 9:  Float2Byte(&Data,DataScope_OutPut_Buffer,33); break;
			case 10: Float2Byte(&Data,DataScope_OutPut_Buffer,37); break;
		}
	}
}


//函数说明：生成 DataScopeV1.0 能正确识别的帧格式
//Channel_Number，需要发送的通道个数
//返回发送缓冲区数据个数
//返回0表示帧格式生成失败
unsigned char DataScope_Data_Generate(unsigned char Channel_Number){
	if((Channel_Number>10)||(Channel_Number==0))
		return 0; //通道个数大于10或等于0，直接跳出，不执行函数
	else{
		DataScope_OutPut_Buffer[0] = '$';  //帧头
		switch(Channel_Number){
			case 1:   DataScope_OutPut_Buffer[5]  =  5; return  6;
			case 2:   DataScope_OutPut_Buffer[9]  =  9; return 10;
			case 3:   DataScope_OutPut_Buffer[13] = 13; return 14;
			case 4:   DataScope_OutPut_Buffer[17] = 17; return 18;
			case 5:   DataScope_OutPut_Buffer[21] = 21; return 22;
			case 6:   DataScope_OutPut_Buffer[25] = 25; return 26;
			case 7:   DataScope_OutPut_Buffer[29] = 29; return 30;
			case 8:   DataScope_OutPut_Buffer[33] = 33; return 34;
			case 9:   DataScope_OutPut_Buffer[37] = 37; return 38;
			case 10:  DataScope_OutPut_Buffer[41] = 41; return 42;
		}
	}
	return 0;
}


#include "ioi2c.h"
#include "sys.h"
#include "delay.h"

void IIC_Init(void){
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE); //使能PB端口时钟
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8|GPIO_Pin_9;	//端口配置
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;      //推挽输出
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;     //50M
	GPIO_Init(GPIOB, &GPIO_InitStructure);					      //根据设定参数初始化GPIO
}

/**************************实现函数********************************************
*函数原型:		void IIC_Start(void)
*功　　能:		产生IIC起始信号
*******************************************************************************/
int IIC_Start(void){
	SDA_OUT();     //sda线输出
	IIC_SDA=1;
	if(!READ_SDA)return 0;
	IIC_SCL=1;
	delay_us(1);
 	IIC_SDA=0;//START:when CLK is high,DATA change form high to low
	if(READ_SDA)return 0;
	delay_us(1);
	IIC_SCL=0;//钳住I2C总线，准备发送或接收数据
	return 1;
}

/**************************实现函数********************************************
*函数原型:		void IIC_Stop(void)
*功　　能:	    //产生IIC停止信号
*******************************************************************************/
void IIC_Stop(void){
	SDA_OUT();//sda线输出
	IIC_SCL=0;
	IIC_SDA=0;//STOP:when CLK is high DATA change form low to high
 	delay_us(1);
	IIC_SCL=1;
	IIC_SDA=1;//发送I2C总线结束信号
	delay_us(1);
}

/**************************实现函数********************************************
*函数原型:		u8 IIC_Wait_Ack(void)
*功　　能:	    等待应答信号到来
//返回值：1，接收应答失败
//        0，接收应答成功
*******************************************************************************/
int IIC_Wait_Ack(void){
	u8 ucErrTime=0;
	SDA_IN();      //SDA设置为输入
	IIC_SDA=1;
	delay_us(1);
	IIC_SCL=1;
	delay_us(1);
	while(READ_SDA){
		ucErrTime++;
		if(ucErrTime>50){
			IIC_Stop();
			return 0;
		}
	  delay_us(1);
	}
	IIC_SCL=0;//时钟输出0
	return 1;
}

/**************************实现函数********************************************
*函数原型:		void IIC_Ack(void)
*功　　能:	    产生ACK应答
*******************************************************************************/
void IIC_Ack(void){
	IIC_SCL=0;
	SDA_OUT();
	IIC_SDA=0;
	delay_us(1);
	IIC_SCL=1;
	delay_us(1);
	IIC_SCL=0;
}

/**************************实现函数********************************************
*函数原型:		void IIC_NAck(void)
*功　　能:	    产生NACK应答
*******************************************************************************/

void IIC_NAck(void){
	IIC_SCL=0;
	SDA_OUT();
	IIC_SDA=1;
	delay_us(1);
	IIC_SCL=1;
	delay_us(1);
	IIC_SCL=0;
}

/**************************实现函数********************************************
*函数原型:		void IIC_Send_Byte(u8 txd)
*功　　能:	    IIC发送一个字节
*******************************************************************************/
void IIC_Send_Byte(u8 txd){
    u8 t;
	SDA_OUT();
    IIC_SCL=0;//拉低时钟开始数据传输
    for(t=0;t<8;t++){
        IIC_SDA=(txd&0x80)>>7;
        txd<<=1;
		delay_us(1);
		IIC_SCL=1;
		delay_us(1);
		IIC_SCL=0;
		delay_us(1);
    }
}

/**************************实现函数********************************************
*函数原型:		bool i2cWrite(uint8_t addr, uint8_t reg, uint8_t data)
*功　　能:
*******************************************************************************/
int i2cWrite(uint8_t addr, uint8_t reg, uint8_t len, uint8_t *data){
	int i;
    if (!IIC_Start())return 1;
    IIC_Send_Byte(addr << 1 );
    if (!IIC_Wait_Ack()) {
        IIC_Stop();
        return 1;
    }
    IIC_Send_Byte(reg);
    IIC_Wait_Ack();
		for (i = 0; i < len; i++) {
        IIC_Send_Byte(data[i]);
        if (!IIC_Wait_Ack()) {
            IIC_Stop();
            return 0;
        }
    }
    IIC_Stop();
    return 0;
}
/**************************实现函数********************************************
*函数原型:		bool i2cWrite(uint8_t addr, uint8_t reg, uint8_t data)
*功　　能:
*******************************************************************************/
int i2cRead(uint8_t addr, uint8_t reg, uint8_t len, uint8_t *buf)
{
    if (!IIC_Start())return 1;
    IIC_Send_Byte(addr << 1);

    if (!IIC_Wait_Ack()) {
        IIC_Stop();
        return 1;
    }

    IIC_Send_Byte(reg);
    IIC_Wait_Ack();
    IIC_Start();
    IIC_Send_Byte((addr << 1)+1);
    IIC_Wait_Ack();
    while (len) {
        if (len == 1) *buf = IIC_Read_Byte(0);
        else *buf = IIC_Read_Byte(1);
        buf++;
        len--;
    }
    IIC_Stop();
    return 0;
}


/**************************实现函数********************************************
*函数原型:		u8 IIC_Read_Byte(unsigned char ack)
*功　　能:	    //读1个字节，ack=1时，发送ACK，ack=0，发送nACK
*******************************************************************************/
u8 IIC_Read_Byte(unsigned char ack){
	unsigned char i,receive=0;
	SDA_IN();//SDA设置为输入
    for(i=0;i<8;i++ ){
        IIC_SCL=0;
        delay_us(2);
		IIC_SCL=1;
        receive<<=1;
        if(READ_SDA)receive++;
		delay_us(2);
    }

    if (ack)IIC_Ack(); //发送ACK
    else IIC_NAck();//发送nACK
    return receive;
}

/**************************实现函数********************************************
*函数原型:		unsigned char I2C_ReadOneByte(unsigned char I2C_Addr,unsigned char addr)
*功　　能:	    读取指定设备 指定寄存器的一个值
输入	I2C_Addr  目标设备地址
		addr	   寄存器地址
返回   读出来的值
*******************************************************************************/
unsigned char I2C_ReadOneByte(unsigned char I2C_Addr,unsigned char addr){
	unsigned char res=0;
	IIC_Start();
	IIC_Send_Byte(I2C_Addr);	   //发送写命令
	res++;
	IIC_Wait_Ack();
	IIC_Send_Byte(addr); res++;  //发送地址
	IIC_Wait_Ack();
	//IIC_Stop();//产生一个停止条件
	IIC_Start();
	IIC_Send_Byte(I2C_Addr+1); res++;          //进入接收模式
	IIC_Wait_Ack();
	res=IIC_Read_Byte(0);
    IIC_Stop();//产生一个停止条件
	return res;
}


/**************************实现函数********************************************
*函数原型:		u8 IICreadBytes(u8 dev, u8 reg, u8 length, u8 *data)
*功　　能:	    读取指定设备 指定寄存器的 length个值
输入	dev  目标设备地址
		reg	  寄存器地址
		length 要读的字节数
		*data  读出的数据将要存放的指针
返回   读出来的字节数量
*******************************************************************************/
u8 IICreadBytes(u8 dev, u8 reg, u8 length, u8 *data){
    u8 count = 0;
	IIC_Start();
	IIC_Send_Byte(dev);	   //发送写命令
	IIC_Wait_Ack();
	IIC_Send_Byte(reg);   //发送地址
    IIC_Wait_Ack();
	IIC_Start();
	IIC_Send_Byte(dev+1);  //进入接收模式
	IIC_Wait_Ack();

    for(count=0;count<length;count++)
		if(count!=length-1)data[count]=IIC_Read_Byte(1);  //带ACK的读数据
		else data[count]=IIC_Read_Byte(0);	 //最后一个字节NACK
    IIC_Stop();//产生一个停止条件
    return count;
}

/**************************实现函数********************************************
*函数原型:		u8 IICwriteBytes(u8 dev, u8 reg, u8 length, u8* data)
*功　　能:	    将多个字节写入指定设备 指定寄存器
输入	dev  目标设备地址
		reg	  寄存器地址
		length 要写的字节数
		*data  将要写的数据的首地址
返回   返回是否成功
*******************************************************************************/
u8 IICwriteBytes(u8 dev, u8 reg, u8 length, u8* data){
 	u8 count = 0;
	IIC_Start();
	IIC_Send_Byte(dev);	   //发送写命令
	IIC_Wait_Ack();
	IIC_Send_Byte(reg);   //发送地址
    IIC_Wait_Ack();
	for(count=0;count<length;count++){
		IIC_Send_Byte(data[count]);
		IIC_Wait_Ack();
	}
	IIC_Stop();//产生一个停止条件

    return 1; //status == 0;
}

/**************************实现函数********************************************
*函数原型:		u8 IICreadByte(u8 dev, u8 reg, u8 *data)
*功　　能:	    读取指定设备 指定寄存器的一个值
输入	dev  目标设备地址
		reg	   寄存器地址
		*data  读出的数据将要存放的地址
返回   1
*******************************************************************************/
u8 IICreadByte(u8 dev, u8 reg, u8 *data){
	*data=I2C_ReadOneByte(dev, reg);
    return 1;
}

/**************************实现函数********************************************
*函数原型:		unsigned char IICwriteByte(unsigned char dev, unsigned char reg, unsigned char data)
*功　　能:	    写入指定设备 指定寄存器一个字节
输入	dev  目标设备地址
		reg	   寄存器地址
		data  将要写入的字节
返回   1
*******************************************************************************/
unsigned char IICwriteByte(unsigned char dev, unsigned char reg, unsigned char data){
    return IICwriteBytes(dev, reg, 1, &data);
}

/**************************实现函数********************************************
*函数原型:		u8 IICwriteBits(u8 dev,u8 reg,u8 bitStart,u8 length,u8 data)
*功　　能:	    读 修改 写 指定设备 指定寄存器一个字节 中的多个位
输入	dev  目标设备地址
		reg	   寄存器地址
		bitStart  目标字节的起始位
		length   位长度
		data    存放改变目标字节位的值
返回   成功 为1
 		失败为0
*******************************************************************************/
u8 IICwriteBits(u8 dev,u8 reg,u8 bitStart,u8 length,u8 data){
    u8 b;
    if (IICreadByte(dev, reg, &b) != 0) {
        u8 mask = (0xFF << (bitStart + 1)) | 0xFF >> ((8 - bitStart) + length - 1);
        data <<= (8 - length);
        data >>= (7 - bitStart);
        b &= mask;
        b |= data;
        return IICwriteByte(dev, reg, b);
    }
	else return 0;
}

/**************************实现函数********************************************
*函数原型:		u8 IICwriteBit(u8 dev, u8 reg, u8 bitNum, u8 data)
*功　　能:	    读 修改 写 指定设备 指定寄存器一个字节 中的1个位
输入	dev  目标设备地址
		reg	   寄存器地址
		bitNum  要修改目标字节的bitNum位
		data  为0 时，目标位将被清0 否则将被置位
返回   成功 为1
 		失败为0
*******************************************************************************/
u8 IICwriteBit(u8 dev, u8 reg, u8 bitNum, u8 data){
    u8 b;
    IICreadByte(dev, reg, &b);
    b = (data != 0) ? (b | (1 << bitNum)) : (b & ~(1 << bitNum));
    return IICwriteByte(dev, reg, b);
}


#include "key.h"

/*
void KEY_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE); //使能端口时钟
  GPIO_InitStructure.GPIO_Pin =GPIO_Pin_5| GPIO_Pin_6;	//端口配置
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;         //上拉输入
  GPIO_Init(GPIOA, &GPIO_InitStructure);					      //根据设定参数初始化GPIO

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE); //使能端口时钟
  GPIO_InitStructure.GPIO_Pin =GPIO_Pin_13| GPIO_Pin_14| GPIO_Pin_15;	            //端口配置
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;         //上拉输入
  GPIO_Init(GPIOC, &GPIO_InitStructure);					      //根据设定参数初始化GPIO

	PWR_BackupAccessCmd(ENABLE);//允许修改RTC 和后备寄存器
	RCC_LSEConfig(RCC_LSE_OFF);//关闭外部低速外部时钟信号功能 后，PC13 PC14 PC15 才可以当普通IO用。
	BKP_TamperPinCmd(DISABLE);//关闭入侵检测功能，也就是 PC13，也可以当普通IO 使用
	PWR_BackupAccessCmd(DISABLE);//禁止修改后备寄存器
}
*/

void KEY_Init(void){
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE); //使能端口时钟
	GPIO_InitStructure.GPIO_Pin =GPIO_Pin_5;	//端口配置
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;         //上拉输入
	GPIO_Init(GPIOA, &GPIO_InitStructure);					      //根据设定参数初始化GPIO
}

/**************************************************************************
函数功能：按键扫描
入口参数：双击等待时间
返回  值：按键状态 0：无动作 1：单击 2：双击
**************************************************************************/
u8 click_N_Double (u8 time){
	static	u8 flag_key,count_key,double_key;
	static	u16 count_single,Forever_count;
	if(KEY_S==0)Forever_count++;   //长按标志位未置1
	else Forever_count=0;
	if(0==KEY_S&&0==flag_key)		flag_key=1;
	if(0==count_key){
		if(flag_key==1){
			double_key++;
			count_key=1;
		}
		if(double_key==2){
			double_key=0;
			count_single=0;
			return 2;//双击执行的指令
		}
	}

	if(1==KEY_S)flag_key=0,count_key=0;

	if(1==double_key){
		count_single++;
		if(count_single>time&&Forever_count<time){
			double_key=0;
			count_single=0;
			return 1;//单击执行的指令
		}
		if(Forever_count>time){
			double_key=0;
			count_single=0;
		}
	}
	return 0;
}
/**************************************************************************
函数功能：按键扫描
入口参数：无
返回  值：按键状态 0：无动作
**************************************************************************/
u8 click(void){
	int  temp;
	static u8 flag_key=1;//按键按松开标志
	if(flag_key&&(KEY_S==0||KEY_P==0||KEY_J==0||KEY_M==0||KEY_X==0)){
		flag_key=0;
		if(KEY_S==0)  temp=1;
		else 	if(KEY_P==0)  temp=2;
		else 	if(KEY_X==0)  temp=3;
		else 	if(KEY_J==0)  temp=4;
		else 	if(KEY_M==0)  temp=5;
		return temp;	  // 按键按下
	}
	else if(1==KEY_S&&1==KEY_P&&1==KEY_J&&1==KEY_M&&1==KEY_X)flag_key=1;
	return 0;//无按键按下
}

/**************************************************************************
函数功能：长按检测
入口参数：无
返回  值：按键状态 0：无动作 1：长按2s
**************************************************************************/
u8 Long_Press(void){
	static u16 Long_Press_count,Long_Press;
	if(Long_Press==0&&KEY_S==0) Long_Press_count++;   //长按标志位未置1
	else Long_Press_count=0;
	if(Long_Press_count>200){
		Long_Press=1;
		Long_Press_count=0;
		return 1;
	}
	if(Long_Press==1)Long_Press=0; //长按标志位置1
	return 0;
}


#include "led.h"
/**************************************************************************
函数功能：BEEP接口初始化
**************************************************************************/
void Beep_Init(void){
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE); //使能端口时钟
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4;	            //端口配置
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;      //推挽输出
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;     //50M
	GPIO_Init(GPIOA, &GPIO_InitStructure);					      //根据设定参数初始化GPIOA
	GPIO_SetBits(GPIOA,GPIO_Pin_4);
}

void BEEP(u8 sta){
	if(sta==0)GPIO_SetBits(GPIOA,GPIO_Pin_4);
	if(sta==1)GPIO_ResetBits(GPIOA,GPIO_Pin_4);
}


#include "stm32f10x.h"
#include "oled.h"
#include "stdlib.h"
#include "oledfont.h"
#include "delay.h"

u8 OLED_GRAM[128][8];
void OLED_Refresh_Gram(void){
	u8 i,n;
	for(i=0;i<8;i++){
		OLED_WR_Byte (0xb0+i,OLED_CMD);    //设置页地址（0~7）
		OLED_WR_Byte (0x00,OLED_CMD);      //设置显示位置—列低地址
		OLED_WR_Byte (0x10,OLED_CMD);      //设置显示位置—列高地址
		for(n=0;n<128;n++)OLED_WR_Byte(OLED_GRAM[n][i],OLED_DATA);
	}
}

//向OLED写入一个字节。
//dat:要写入的数据/命令
//cmd:数据/命令标志 0,表示命令;1,表示数据;
void OLED_WR_Byte(u8 dat,u8 cmd){
	u8 i;
	if(cmd)OLED_RS_Set();
	else OLED_RS_Clr();

	for(i=0;i<8;i++){
		OLED_SCLK_Clr();
		if(dat&0x80)OLED_SDIN_Set();
		elseOLED_SDIN_Clr();
		OLED_SCLK_Set();
		dat<<=1;
	}

	OLED_RS_Set();
}


//开启OLED显示
void OLED_Display_On(void){
	OLED_WR_Byte(0X8D,OLED_CMD);  //SET DCDC命令
	OLED_WR_Byte(0X14,OLED_CMD);  //DCDC ON
	OLED_WR_Byte(0XAF,OLED_CMD);  //DISPLAY ON
}
//关闭OLED显示
void OLED_Display_Off(void){
	OLED_WR_Byte(0X8D,OLED_CMD);  //SET DCDC命令
	OLED_WR_Byte(0X10,OLED_CMD);  //DCDC OFF
	OLED_WR_Byte(0XAE,OLED_CMD);  //DISPLAY OFF
}
//清屏函数,清完屏,整个屏幕是黑色的!和没点亮一样!!!
void OLED_Clear(void){
	u8 i,n;
	for(i=0;i<8;i++)
		for(n=0;n<128;n++)
			OLED_GRAM[n][i]=0X00;
	OLED_Refresh_Gram();//更新显示
}
//画点
//x:0~127
//y:0~63
//t:1 填充 0,清空
void OLED_DrawPoint(u8 x,u8 y,u8 t){
	u8 pos,bx,temp=0;
	if(x>127||y>63)return;//超出范围了.
	pos=7-y/8;
	bx=y%8;
	temp=1<<(7-bx);
	if(t)OLED_GRAM[x][pos]|=temp;
	else OLED_GRAM[x][pos]&=~temp;
}

//在指定位置显示一个字符,包括部分字符
//x:0~127
//y:0~63
//mode:0,反白显示;1,正常显示
//size:选择字体 16/12
void OLED_ShowChar(u8 x,u8 y,u8 chr,u8 size,u8 mode){
	u8 temp,t,t1;
	u8 y0=y;
	chr=chr-' ';//得到偏移后的值
    for(t=0;t<size;t++){
		if(size==12)temp=oled_asc2_1206[chr][t];  //调用1206字体
		else temp=oled_asc2_1608[chr][t];		 //调用1608字体
        for(t1=0;t1<8;t1++){
			if(temp&0x80)OLED_DrawPoint(x,y,mode);
			else OLED_DrawPoint(x,y,!mode);
			temp<<=1;
			y++;
			if((y-y0)==size){
				y=y0;
				x++;
				break;
			}
		}
    }
}

//m^n函数
u32 oled_pow(u8 m,u8 n){
	u32 result=1;
	while(n--)result*=m;
	return result;
}

//显示2个数字
//x,y :起点坐标
//len :数字的位数
//size:字体大小
//mode:模式	0,填充模式;1,叠加模式
//num:数值(0~4294967295);
void OLED_ShowNumber(u8 x,u8 y, u32 num,u8 len,u8 size){
	u8 t,temp;
	u8 enshow=0;

	for(t=0;t<len;t++){
		temp=(num/oled_pow(10,len-t-1))%10;
		if(enshow==0&&t<(len-1)){
			if(temp==0){
				OLED_ShowChar(x+(size/2)*t,y,' ',size,1);
				continue;
			}
			else enshow=1;
		}
	 	OLED_ShowChar(x+(size/2)*t,y,temp+'0',size,1);
	}

}

//显示字符串
//x,y:起点坐标
// *p:字符串起始地址
//用16字体
void OLED_ShowString(u8 x,u8 y,const u8 *p){
	#define MAX_CHAR_POSX 122
	#define MAX_CHAR_POSY 58
    while(*p!='\0'){
        if(x>MAX_CHAR_POSX){x=0;y+=16;}
        if(y>MAX_CHAR_POSY){y=x=0;OLED_Clear();}
        OLED_ShowChar(x,y,*p,12,1);
        x+=6;
        p++;
    }
}
//void show_chinese(u8 x,u8 y,u8 *str)
//初始化OLED
void show_float_num1(u8 x,u8 y, float number){
	u8 buff[6];
	sprintf(buff,"%.4f",number);
	OLED_ShowString(x,y,buff);
}

void OLED_Init(void){
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE); //使能PB端口时钟
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3|GPIO_Pin_4|GPIO_Pin_5;//端口配置
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;      //推挽输出
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;     //2M
	GPIO_Init(GPIOB, &GPIO_InitStructure);		//根据设定参数初始化GPIO

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);//开A口时钟。
	GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_15;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;       //设为输出　
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Init(GPIOA, &GPIO_InitStructure);

	PWR_BackupAccessCmd(ENABLE);//允许修改RTC 和后备寄存器
	RCC_LSEConfig(RCC_LSE_OFF);//关闭外部低速外部时钟信号功能 后，PC13 PC14 PC15 才可以当普通IO用。
	BKP_TamperPinCmd(DISABLE);//关闭入侵检测功能，也就是 PC13，也可以当普通IO 使用
	PWR_BackupAccessCmd(DISABLE);//禁止修改后备寄存器

	OLED_RST_Clr();
	delay_ms(100);
	OLED_RST_Set();

	OLED_WR_Byte(0xAE,OLED_CMD); //关闭显示
	OLED_WR_Byte(0xD5,OLED_CMD); //设置时钟分频因子,震荡频率
	OLED_WR_Byte(80,OLED_CMD);   //[3:0],分频因子;[7:4],震荡频率
	OLED_WR_Byte(0xA8,OLED_CMD); //设置驱动路数
	OLED_WR_Byte(0X3F,OLED_CMD); //默认0X3F(1/64)
	OLED_WR_Byte(0xD3,OLED_CMD); //设置显示偏移
	OLED_WR_Byte(0X00,OLED_CMD); //默认为0

	OLED_WR_Byte(0x40,OLED_CMD); //设置显示开始行 [5:0],行数.

	OLED_WR_Byte(0x8D,OLED_CMD); //电荷泵设置
	OLED_WR_Byte(0x14,OLED_CMD); //bit2，开启/关闭
	OLED_WR_Byte(0x20,OLED_CMD); //设置内存地址模式
	OLED_WR_Byte(0x02,OLED_CMD); //[1:0],00，列地址模式;01，行地址模式;10,页地址模式;默认10;
	OLED_WR_Byte(0xA1,OLED_CMD); //段重定义设置,bit0:0,0->0;1,0->127;
	OLED_WR_Byte(0xC0,OLED_CMD); //设置COM扫描方向;bit3:0,普通模式;1,重定义模式 COM[N-1]->COM0;N:驱动路数
	OLED_WR_Byte(0xDA,OLED_CMD); //设置COM硬件引脚配置
	OLED_WR_Byte(0x12,OLED_CMD); //[5:4]配置

	OLED_WR_Byte(0x81,OLED_CMD); //对比度设置
	OLED_WR_Byte(0xEF,OLED_CMD); //1~255;默认0X7F (亮度设置,越大越亮)
	OLED_WR_Byte(0xD9,OLED_CMD); //设置预充电周期
	OLED_WR_Byte(0xf1,OLED_CMD); //[3:0],PHASE 1;[7:4],PHASE 2;
	OLED_WR_Byte(0xDB,OLED_CMD); //设置VCOMH 电压倍率
	OLED_WR_Byte(0x30,OLED_CMD); //[6:4] 000,0.65*vcc;001,0.77*vcc;011,0.83*vcc;

	OLED_WR_Byte(0xA4,OLED_CMD); //全局显示开启;bit0:1,开启;0,关闭;(白屏/黑屏)
	OLED_WR_Byte(0xA6,OLED_CMD); //设置显示方式;bit0:1,反相显示;0,正常显示
	OLED_WR_Byte(0xAF,OLED_CMD); //开启显示
	OLED_Clear();
}

#include "car.h"

/*
#define  qian  1
#define  hou   2
#define  right 1
#define  left  2

*/
/**********
函数名：void trail_gpio_init()
功能： 尾部寻迹模块的IO口初始化
PA６　PA11 PB0
************/

u8 PriFlag=0;//优先级
void tail_trail_init(){
	RCC->APB2ENR|=1<<2;
	RCC->APB2ENR|=1<<3;
	GPIOA->CRL&=0XF0FFFFFF;
	GPIOA->CRL|=0x04000000;
	GPIOA->CRH&=0XFFFF0FFF;
	GPIOA->CRH|=0X00004000;
	GPIOB->CRL&=0XFFFFFFF0;
	GPIOB->CRL|=0X00000004;
}

/**********
函数名：void head_gpio_init()
功能： 头部寻迹模块的IO口初始化
Pc13　Pc14 Pc15
************/
void head_trail_init(){
	GPIO_InitTypeDef GPIO_InitStructure;

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE );
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13  |
	GPIO_Pin_14 |
	GPIO_Pin_15  ;
	GPIO_InitStructure.GPIO_Mode  =  GPIO_Mode_IN_FLOATING;

	GPIO_Init(GPIOC, &GPIO_InitStructure);

	PWR_BackupAccessCmd(ENABLE);
	RCC_LSEConfig(RCC_LSE_OFF);
	PWR_BackupAccessCmd(DISABLE);

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE); //使能PB端口时钟
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4|GPIO_Pin_5;//端口配置
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_Init(GPIOB, &GPIO_InitStructure);					      //根据设定参数初始化GPIO
	 /*	RCC->APB2ENR|=1<<4;
		RCC->APB2ENR|=1<<0;
	  GPIOC->CRH&=0X000FFFFF;
		GPIOC->CRH|=0x44400000;

		PWR_BackupAccessCmd(ENABLE);//允许修改RTC 和后备寄存器
	  RCC_LSEConfig(RCC_LSE_OFF);//关闭外部低速外部时钟信号功能 后，PC13 PC14 PC15 才可以当普通IO用。
	  BKP_TamperPinCmd(DISABLE);//关闭入侵检测功能，也就是 PC13，也可以当普通IO 使用
	  PWR_BackupAccessCmd(DISABLE);//禁止修改后备寄存器
*/
}
/**********
函数名：void move(u8 direction ,float duty)
功能：  小车前进后退
参数：u8 direction：qian  1
                     hou   2
      float duty:占空比（速度控制）

前进：IN1 :1
      IN2 :0
			IN3 :1
      IN4 :0
output_pwm(u8 chnl,float duty)

************/
void move(u8 direction,float duty){
	if(direction==qian){
		output_pwm(1,duty);
		output_pwm(2,0);
		output_pwm(3,duty);
		output_pwm(4,0);
	}
    if(direction==hou){
		output_pwm(1,0);
		output_pwm(2,duty);
		output_pwm(3,0);
		output_pwm(4,duty);
	}
}
/**********************************************

功能：  小车前进方向转向
**********************************************/
void turn(u8 direction, float duty)
{
	 if(direction==left){
		output_pwm(3,duty);
		output_pwm(1,0);
		output_pwm(2,duty*0.8);
		output_pwm(4,0);
	}
	if(direction==right){
		output_pwm(2,0);
		output_pwm(1,duty);
		output_pwm(3,0);
		output_pwm(4,duty*0.8);
	}
}

/**********************************************
函数名：void car_stop()
功能：  让小车停止
**********************************************/
void car_stop(){
    output_pwm(3,0);
	output_pwm(4,0);
    output_pwm(1,0);
	output_pwm(2,0);
}

/**********************************************
函数名?void HideMove()
功能：  蔽障功能

参数：
#define  HL PBin(5) //车头左边
#define  HR PAin(11) //车头右边
#define  TR PBin(0) //车尾右边
#define  TL PAin(6) //车头左边
**********************************************/
u8 ChangeFlag=0;
extern u8 count;
extern u8 step;
void HideMove(){
	if((HL==0)&&(HR==1)&&(TR==1)&&(TL==1)){
		PriFlag=1;
		printf("aaa\n");
		ChangeFlag=1;
		count=0;
		step=0;
	}
	else if((HL==1)&&(HR==0)&&(TR==1)&&(TL==1)){
		PriFlag=2;
		printf("bbb\n");
		ChangeFlag=1;
		count=0;
		step=0;
	}
	else if((HL==1)&&(HR==1)&&(TR==0)&&(TL==1)){
		PriFlag=3;
		printf("ccc\n");
		ChangeFlag=1;
		count=0;
		step=0;
	}
	else if((HL==1)&&(HR==1)&&(TR==1)&&(TL==0)){
		PriFlag=4;
		printf("ddd\n");
		ChangeFlag=1;
		count=0;
		step=0;
	}
	else if((HL==1)&&(HR==1)&&(TR==0)&&(TL==0)){
		move(qian,0.8);
		printf("eee\n");
		ChangeFlag=1;
		count=0;
		step=0;
	}
	else if((HL==0)&&(HR==0)&&(TR==1)&&(TL==1)){
		PriFlag=5;
		printf("fff\n");
		ChangeFlag=1;
		count=0;
		step=0;

	}
}


#include "stm32f10x.h"
#include "control.h"
#include "sys.h"
#include "math.h"

u8 Flag_Way=0,Flag_Show=0;                 //停止标志位和 显示标志位 默认停止 显示打开
int Servo1,Servo2,Servo3,Servo4,Servo5;     //电机PWM变量
float Speed=10;                   //运动速度设置
int Voltage;                      //电池电压采样相关的变量
#define Pi 3.1416
u8 delay_50,delay_flag,Bi_zhang=0,PID_Send,Flash_Send; //延时和调参等变量
float Balance_Kp=350,Balance_Kd=0,Velocity_Kp=70,Velocity_Ki=0.7;//PID参数
u16 PID_Parameter[10],Flash_Parameter[10];  //Flash相关数组
float Target_X=750,Target_Y=750	,Target_Z=750;
//float Target1=680,Target2=730,Target3=770,Target4=730,Target5=450,Target6=800;     //电机初始值
float Target1=680,Target2=960,Target3=990,Target4=700,Target5=450,Target6=3000;     //电机初始值
float TargetX,TargetY,TargetZ,Target_Beta=0,Target_Alpha=0,Target_Gamma=0;     					//电机目标值
float	Position_KP=6,Position_KI=0,Position_KD=3;  //位置控制PID参数
int PS2_LX,PS2_LY,PS2_RX,PS2_RY,PS2_KEY;
int datalen;
int dataIdx=0;
int re_x,re_y;
int r_color;
u8 start_flag;
u8 zhua_flag=0;
u8 error_flag=0;

int main(void){
	delay_init();	    	            //=====延时函数初始化
	uart_init(9600);	            //=====串口初始化为
	Beep_Init();
	JTAG_Set(SWD_ENABLE);           //=====打开SWD接口 可以利用主板的SWD接口调试
	KEY_Init();                     //=====按键初始化
	MY_NVIC_PriorityGroupConfig(2); //=====中断分组
	delay_ms(100);                  //=====延时等待
	uart3_init(9600);               //=====串口3初始化
	delay_ms(100);                  //=====延时等待
	//Timer3InitConfig();
	TIM2_Int_Init(99,7199);         //=====定时器10ms中断
	TIM1_PWM_Init(9999,143);        //=====PWM初始化
	TIM4_PWM_Init(9999,143);        //=====PWM初始化
	Time2_pwm_init();
	tail_trail_init();
	head_trail_init();

	while(1)
	{
		if(RXFLAG==1)
		{
			dataIdx=0;
			RXBuff[RXCENT] = '\0';
			//printf("%s\n","here1");
			//	printf("%s\n",RXBuff);

			if(CRStrLib_isValidData(RXBuff, "HEAD", "TAIL")==TRUE) //
			{
				//printf("1");
				datalen= CRStrLib_strLen(RXBuff);  //
				//CRStrLib_findNextFloat(RXBuff, datalen, &dataIdx, &re_x);
				//CRStrLib_findNextFloat(RXBuff, datalen, &dataIdx, &re_y);
				//CRStrLib_findNextFloat(RXBuff,datalen, &dataIdx, &re_z);
				CRStrLib_findNextInt(RXBuff,datalen, &dataIdx, &re_x);  //
				CRStrLib_findNextInt(RXBuff,datalen, &dataIdx, &re_y);  //
				//CRStrLib_findNextInt(char *str, int strLen, int *strIdx, int *result)
				//printf("x:%.4f y:%.4f z:%.4f a:%d\n",re_x,re_y,re_z,r_qi);
				RXCENT=0;
				RXFLAG = 0;//接收完成标志位清零
				if((re_x<400)&&(re_y<400))
				{
					start_flag=1;
					error_flag=0;
				}
			}
			else
			{
				printf("2");
				RXCENT=0;
				RXFLAG = 0;//接收完成标志位清零
				//start_flag=1;
			}
		}

		delay_flag=1;
		delay_50=0;
		while(delay_flag);  //
	}
}
