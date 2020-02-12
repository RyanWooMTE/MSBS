function RTW_Sid2UrlHash() {
	this.urlHashMap = new Array();
	/* <Root>/enable */
	this.urlHashMap["cruise_control_sdo:1"] = "cruise_control_sdo.c:170";
	/* <Root>/brake_pressure */
	this.urlHashMap["cruise_control_sdo:2"] = "cruise_control_sdo.c:169";
	/* <Root>/set */
	this.urlHashMap["cruise_control_sdo:3"] = "cruise_control_sdo.c:58,171";
	/* <Root>/inc */
	this.urlHashMap["cruise_control_sdo:4"] = "cruise_control_sdo.c:57";
	/* <Root>/dec */
	this.urlHashMap["cruise_control_sdo:5"] = "cruise_control_sdo.c:56,111";
	/* <Root>/driver_throt */
	this.urlHashMap["cruise_control_sdo:6"] = "cruise_control_sdo.c:230";
	/* <Root>/speed */
	this.urlHashMap["cruise_control_sdo:7"] = "cruise_control_sdo.c:64,162,172";
	/* <Root>/PI_Controller */
	this.urlHashMap["cruise_control_sdo:58"] = "cruise_control_sdo.c:184,222&cruise_control_sdo.h:48";
	/* <Root>/Saturation */
	this.urlHashMap["cruise_control_sdo:54"] = "cruise_control_sdo.c:63,110,226,229,237";
	/* <Root>/Switch */
	this.urlHashMap["cruise_control_sdo:17"] = "cruise_control_sdo.c:224,235";
	/* <S1>/is_ctrl */
	this.urlHashMap["cruise_control_sdo:66"] = "cruise_control_sdo.c:185";
	/* <S1>/Gain1 */
	this.urlHashMap["cruise_control_sdo:60"] = "cruise_control_sdo.c:201,211";
	/* <S1>/Kp */
	this.urlHashMap["cruise_control_sdo:61"] = "cruise_control_sdo.c:195";
	/* <S1>/Sum1 */
	this.urlHashMap["cruise_control_sdo:62"] = "cruise_control_sdo.c:194&cruise_control_sdo.h:46";
	/* <S1>/Sum2 */
	this.urlHashMap["cruise_control_sdo:63"] = "cruise_control_sdo.c:212";
	/* <S1>/Unit Delay2 */
	this.urlHashMap["cruise_control_sdo:64"] = "cruise_control_sdo.c:189,196,210,213&cruise_control_sdo.h:47";
	/* <S2>/Constant1 */
	this.urlHashMap["cruise_control_sdo:23"] = "cruise_control_sdo.c:70";
	/* <S2>/Constant3 */
	this.urlHashMap["cruise_control_sdo:24"] = "cruise_control_sdo.c:89";
	/* <S2>/Saturation */
	this.urlHashMap["cruise_control_sdo:25"] = "cruise_control_sdo.c:120,159";
	/* <S2>/Sum */
	this.urlHashMap["cruise_control_sdo:26"] = "cruise_control_sdo.c:69,82";
	/* <S2>/Sum1 */
	this.urlHashMap["cruise_control_sdo:27"] = "cruise_control_sdo.c:161";
	/* <S2>/Sum2 */
	this.urlHashMap["cruise_control_sdo:28"] = "cruise_control_sdo.c:88,102";
	/* <S2>/Switch1 */
	this.urlHashMap["cruise_control_sdo:29"] = "cruise_control_sdo.c:55,118";
	/* <S2>/Switch2 */
	this.urlHashMap["cruise_control_sdo:30"] = "cruise_control_sdo.c:59,71,81,90,103,112";
	/* <S2>/Switch3 */
	this.urlHashMap["cruise_control_sdo:31"] = "cruise_control_sdo.c:60,91,101,113";
	/* <S2>/Unit Delay */
	this.urlHashMap["cruise_control_sdo:32"] = "cruise_control_sdo.c:83,104";
	/* <S3>/Constant */
	this.urlHashMap["cruise_control_sdo:41"] = "cruise_control_sdo.c:167";
	/* <S3>/Constant1 */
	this.urlHashMap["cruise_control_sdo:42"] = "cruise_control_sdo.c:168";
	/* <S3>/Logical
Operator */
	this.urlHashMap["cruise_control_sdo:43"] = "cruise_control_sdo.c:166";
	/* <S3>/Logical
Operator1 */
	this.urlHashMap["cruise_control_sdo:44"] = "cruise_control_sdo.c:173";
	/* <S3>/Logical
Operator2 */
	this.urlHashMap["cruise_control_sdo:45"] = "cruise_control_sdo.c:174";
	/* <S3>/Logical
Operator3 */
	this.urlHashMap["cruise_control_sdo:46"] = "cruise_control_sdo.c:175";
	/* <S3>/Relational
Operator */
	this.urlHashMap["cruise_control_sdo:47"] = "cruise_control_sdo.c:176";
	/* <S3>/Relational
Operator1 */
	this.urlHashMap["cruise_control_sdo:48"] = "cruise_control_sdo.c:177";
	/* <S3>/Unit Delay1 */
	this.urlHashMap["cruise_control_sdo:49"] = "cruise_control_sdo.c:179";
	/* <S4>/Compare */
	this.urlHashMap["cruise_control_sdo:40:2"] = "cruise_control_sdo.c:178";
	/* <S4>/Constant */
	this.urlHashMap["cruise_control_sdo:40:3"] = "msg=rtwMsg_notTraceable&block=cruise_control_sdo/isControlActivate/Compare%20To%20Constant/Constant";
	this.getUrlHash = function(sid) { return this.urlHashMap[sid];}
}
	RTW_Sid2UrlHash.instance = new RTW_Sid2UrlHash();
