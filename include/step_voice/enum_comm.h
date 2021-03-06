enum request_type {
    FRAME,
    READ,
    WRITE

};

enum comm_status {
    WRONG_CRC=-2,
    NO_VALUE=-1,    
    NO_COMM=-1,
    COMM_NO_FRAME=0,
    COMM_FRAME=1,
    US_TIMEOUT=65535,
    US_DEADZONE=0
};

enum received_values {

    DATA=1,
    CRC=2
};

enum data_format {
    ADDRESS=0,
    NO_DATA=2,
    _8BIT=4,
    _16BIT=6,
    _32BIT=8
};

enum gui_commands {
    NONE=-2,
    COMMAND=-1,
    START_STOP=0

};


enum frame_type {
    STOP=1,
    START=2,
    RESET=3,
    EVENT=4,
    BAUD_RATE=5,
    NEWHEARTBEAT=6,
    SYNC=7,
    REGISTRY_W=8,
    REGISTRY_S=9,
    REGISTRY_R=10,
    REGISTRY_WT=11,
    REGISTRY_RT=12,
    REGISTRY_TD=13
};

enum comm_direction {
    OUT=0,
    IN=1
};

enum device_id {
    DEVICE_COUNT=11,
    HUB=0,
    PUMP=1,
    MOP_DRIVER=2,
    US3=3,
    US4=4,
    PERIPH=7,
    FLOOR=8,
    CL_HEAD=9,
    POWER_PCB=10,

    LIGHTS=100,
};

enum hub_event {
    //NO_EVENT=0,
    ERROR_MODE=0,
    NO_HEARTBEAT=1,
    NO_SYNC=2,
    RESTART_EVENT=3,
    DEVICE_LOST=4,

};

enum dev_event {
    BAUDRATE_CHANGED=4,
    PRESSURE_TO_HIGHT_ERROR=5,
    EVENT_CURRENT_TO_HIGHT_ERROR=6,
    EVENT_PRESSURE_THRESHOLD=7,
    EVENT_CURRENT_THRESHOLD=8
};

enum reg_sensor {
    REG_SENSOR0=0,   //","UINT16","R"
    REG_SENSOR1=1, //UINT16","R"
    REG_SENSOR2=2, //UINT16","R"
    REG_SENSOR3=3, //UINT16","R"
    REG_SENSOR4=4, //UINT16","R"
    REG_SENSOR5=5, //UINT16","R"
    REG_SENSOR6=6, //UINT16","R"
    REG_SENSOR7=7, //UINT16","R"
};

enum reg_general {
    REG_START_REQUEST,
    REG_STOP_REQUEST,
    REG_RESET_REQUEST,
    REG_DEV_MODE,
    REG_EVENT,
    REG_SYNC_MODE,
    REG_HEARTBEAT_MODE,
    REG_RX_FRAME_STAT=7,
    REG_TX_FRAME_STAT=8,
    REG_ERROR_STAT,
    REG_PERIOD_HB,
    REG_TIMEOUT_SYNC,
    REG_RESTART_REASON,
    REG_SYNC_FRAME_NUMBER,
    REG_CAN_BAUDRATE,
    REG_BUS_ERR_COUNTER,

    REG_FIRST_GROUP=0,     //addres of the first register from the first group
    REG_SECOND_GROUP=50,     //addres of the first register from the second group
    REG_MAX_COUNT=100       //maximal anticipated count of the registers
};

enum reg_hub {
    REG_DEVICES_1=50, //UINT32","R"
    REG_DEVICES_2=51, //","UINT32","R"

    REG_SYNC_BUS_TIME_10KBS=52, //UINT16","RW"
    REG_SYNC_BUS_TIME_20KBS=53, //UINT16","RW"
    REG_SYNC_BUS_TIME_50KBS=54, //UINT16","RW"
    REG_SYNC_BUS_TIME_125KBS=55, //UINT16","RW"
    REG_SYNC_BUS_TIME_250KBS=56, //UINT16","RW"
    REG_SYNC_BUS_TIME_500KBS=57, //UINT16","RW"
    REG_SYNC_BUS_TIME_1000KBS=58, //UINT16","RW"
    REG_SYNC_BUS_TIME_PERCENT_FACTOR=59,    //UINT16","RW"

    REG_LOST_DEVICES_1=60,
    REG_LOST_DEVICES_2=61
};

enum reg_mop_driver {

    REG_MOP_DRIVER=50, //address of the first register
    REG_MOP_DRIVER_COUNT=13,

    PERY_ON=0, //BOOL","RW"

    CLEAR_VALVE_ON=1, //BOOL","RW"

    DIRT_VALVE_ON=2, //BOOL","RW"

    WASHING_PUMP_ON=3, //","BOOL","RW"

    LINEAR_ACTUATOR_POSITION=4, //UINT16","RW"

    CLEAR_PERY_ML=5, //UINT16","RW"

    DETERGENT_PERY_PERMILS=6, //UINT16","RW"

    PRESENT_CLEAR_FLOW=7, //UINT16","R"

    MAX_CLEAR_FLOW_DIFFERENCE=8, //UINT16","R"

    PRESENT_DETERGENT_FLOW=9, //UINT16","R"

    CLEAR_W_LEVEL=10, //UINT16","R"

    DIRT_W_LEVEL=11, //UINT16","R"

    DETERGENT_LEVEL=12 //UINT16","R"
};

enum reg_pump {
    REG_PUMP=50, //address of the first register
    REG_PUMP_COUNT=15,

    REG_MOTOR_PERCENT_POWER=0, //UINT8","RW"

    REG_MOTOR_PWM_FREQUENCY=1, //UINT16","RW"

    PROFILER_ONE_STEP_TIME=2, //UINT16","RW"

    REG_MOTOR_CURRENT=3, //UINT16","R"

    CURRENT_THRESHOLD_TIMING=4, //UINT16","RW"

    CURRENT_THRESHOLD=5, //UINT16","RW"

    CURRENT_EVENT_ENABLE=6, //BOOL","RW"

    CURRENT_STOP_THRESHOLD=7, //UINT16","RW"

    CURRENT_STOP_ENABLE=8, //BOOL","RW"

    REG_MOTOR_PRESSURE=9, //UINT16","R"

    PRESSURE_THRESHOLD_TIMING=10, //UINT16","RW"

    PRESSURE_THRESHOLD=11, //UINT16","RW"

    PRESSURE_EVENT_ENABLE=12, //BOOL","RW"

    PRESSURE_STOP_THRESHOLD=13, //UINT16","RW"

    PRESSURE_STOP_ENABLE=14 //BOOL","RW"

};

enum reg_us {
    REG_US=50, //address of the first register
    REG_US_COUNT=20,
    REG_US_SENSOR_COUNT=8,

    //0-7 ->REG_SENSORx
    REG_SENSOR_STATE=8, //UINT8","RW"
    REG_TRIGGER_MEASUREMENT=9, //bool","RW"
    REG_TRIGGER_ID=10, //UINT8","RW"
    REG_SENSOR0_DEADZONE=11, //","UINT16","RW"
    REG_SENSOR1_DEADZONE=12, //","UINT16","RW"
    REG_SENSOR2_DEADZONE=13, //","UINT16","RW"
    REG_SENSOR3_DEADZONE=14, //","UINT16","RW"
    REG_SENSOR4_DEADZONE=15, //","UINT16","RW"
    REG_SENSOR5_DEADZONE=16, //","UINT16","RW"
    REG_SENSOR6_DEADZONE=17, //","UINT16","RW"
    REG_SENSOR7_DEADZONE=18, //","UINT16","RW"
    REG_STOP=19 //","bool","RW"

};

enum reg_periph {
    REG_PERIPH=50, //address of the first register
    REG_PERIPH_COUNT=5,
    REG_PERIPH_OUTPUTS_COUNT=12,

    REG_INPUTS_STATE=0, //UINT16","R"
    REG_OUTPUTS_STATE=1, //UINT16","RW"
    REG_SHIFTER_ACCEL=2, //"UINT16","R"
    REG_SHIFTER_STEER=3, //UINT16","R"
    REG_ACCESS_LEVEL=4, //UINT8","R"
};

enum reg_floor {
    REG_FLOOR=50, //address of the first register
    REG_FLOOR_COUNT=7,
    REG_FLOOR_SENSOR_COUNT=6,
    //0-5 ->REG_SENSORx
    REG_SEND_FREQ=6 //UINT16","RW"
};

enum reg_clhead {
    REG_CLHEAD=50, //address of the first register
    REG_CLHEAD_COUNT=18,

    REG_MAIN_BRUSH_SPEED=0, //","UINT16","RW"

    REG_SIDE_BRUSH_SPEED=1, //","UINT16","RW"

    REG_MAIN_BRUSH_POSITION=2, //","UINT8","RW"

    REG_MAIN_BRUSH_POSITION_TRANSPORTATION=3,//","UINT16","RW"

    REG_MAIN_BRUSH_POSITION_SERVICE=4,//","UINT16","RW"

    REG_MAIN_BRUSH_CURRENT_SETTINGS=5,//","UINT16","RW"

    REG_MAIN_BRUSH_WIDTH=6,//","UINT16","RW"

    REG_CL_SENSOR1=7, //","BOOL","R"

    REG_CL_SENSOR2=8, //","BOOL","R"

    REG_CL_SENSOR3=9,//","BOOL","R"

    REG_CL_SENSOR4=10, //","BOOL","R"

    REG_CL_SENSOR5=11,//","BOOL","R"

    REG_BATTERY_VOLTAGE=12, //","UINT16","R"

    REG_MAIN_BRUSH_CURRENT=13, //","UINT16","R"

    REG_MAIN_BRUSH_CURR_LIMIT=14,   //","UINT16","RW"

    REG_SIDE_BRUSH_CURRENT=15, //","UINT16","R"

    REG_SIDE_BRUSH_CURR_LIMIT=16,   //","UINT16","RW"

    REG_CHM_STATUS=17,  //","UINT32","R"
};

enum reg_powerpcb {
    REG_POWERPCB=50, //address of the first register
    REG_POWERPCB_COUNT=49,

    REG_VOLTAGE=0, //UINT16","R"
    REG_CURRENT=1, //UINT16","R"
    REG_TIME_ALIVE=2, //"UINT16","R"
    REG_SWITCHOFF=3, //UINT16","R"

    REG_SWITCHOFF_OK,
    REG_SWITCHOFF_ERROR,

    REG_TEMP11,
    REG_TEMP12,
    REG_TEMP13,
    REG_TEMP14,
    REG_TEMP15,
    REG_TEMP16,
    REG_TEMP17,
    REG_TEMP21,
    REG_TEMP22,
    REG_TEMP23,
    REG_TEMP24,
    REG_TEMP25,
    REG_TEMP26,
    REG_TEMP27,
    REG_TEMP_R1,
    REG_TEMP_R2,
    REG_TEMP_R3,

    REG_TEMP_R4,
    REG_TEMP_R5,
    REG_TEMP_R6,
    REG_TEMP_R7,
    REG_TEMP_R8,
    REG_TEMP_R9,
    REG_TEMP_R10,
    REG_TEMP_R11,

    REG_VOLT,

    REG_VOLT_11,
    REG_VOLT_12,
    REG_VOLT_13,
    REG_VOLT_14,
    REG_VOLT_15,
    REG_VOLT_16,

    REG_VOLT_21,
    REG_VOLT_22,
    REG_VOLT_23,
    REG_VOLT_24,
    REG_VOLT_25,
    REG_VOLT_26,



    REG_BATT_TIME_ALIVE,
    REG_TIME_LAST_CHARGE,
    REG_DURATION_CURR_CHARGE,
    REG_DURATION_LAST_CHARGE,
    REG_CHARGE_COUNT,


};

enum lights{
    STROBO_BLINK=7,
    STROBO_BEACON=8,
    FRONT_LIGHTS=9,
    INDICATOR_LEFT=10,
    INDICATOR_RIGHT=11,
};

enum periph_inputs{
    ACCESS_HOOD=0,
    ACCU_HOOD=1,
    COMPUTER_HOOD=2,
    FILTER_IN=3,
    BAG_IN=4,
    KILLSWITCH=6,
};
