<?php session_start();
if (!isset($_SESSION['user_id'])){
	require_once("oj-header.php");
	echo "<a href='loginpage.php'>$MSG_Login</a>";
	require_once("oj-footer.php");
	exit(0);
}
require_once("include/db_info.inc.php");
require_once("include/const.inc.php");
$now=strftime("%Y-%m-%d %H:%M",time());
$user_id=$_SESSION['user_id'];

        $sql="SELECT count(1) FROM `solution` WHERE result<4";
        $result=pdo_query($sql);
         $row=$result[0];
        if($row[0]>20) $OJ_VCODE=true;
        
if($OJ_VCODE)$vcode=$_POST["vcode"];
if($OJ_VCODE&&($_SESSION["vcode"]==null||$vcode!= $_SESSION["vcode"]||$vcode==""||$vcode==null) ){
        $_SESSION["vcode"]=null;
        $err_str=$err_str."Verification Code Wrong!\\n";
        $err_cnt++;
	exit(0);
}

if (isset($_POST['cid'])){
	$pid=intval($_POST['pid']);
	$cid=intval($_POST['cid']);
	$sql="SELECT `problem_id` from `contest_problem` 
				where `num`='$pid' and contest_id=$cid";
}else{
	$id=intval($_POST['id']);
	$sql="SELECT `problem_id` from `problem` where `problem_id`='$id' and problem_id not in (select distinct problem_id from contest_problem where `contest_id` IN (
			SELECT `contest_id` FROM `contest` WHERE 
			(`end_time`>'$now' or private=1)and `defunct`='N'
			))";
	if(!isset($_SESSION['administrator']))
		$sql.=" and defunct='N'";
}
//echo $sql;	

$res=pdo_query($sql);
if ($res&&count($res)<1&&!isset($_SESSION['administrator'])&&!((isset($cid)&&$cid<=0)||(isset($id)&&$id<=0))){
		
		$view_errors=  "Where do find this link? No such problem.<br>";
		require("template/".$OJ_TEMPLATE."/error.php");
		exit(0);
}




$test_run=false;
if (isset($_POST['id'])) {
	$id=intval($_POST['id']);
        $test_run=($id<=0);
}else if (isset($_POST['pid']) && isset($_POST['cid'])&&$_POST['cid']!=0){
	$pid=intval($_POST['pid']);
	$cid=intval($_POST['cid']);
        $test_run=($cid<0);
	if($test_run) $cid=-$cid;
	// check user if private
	$sql="SELECT `private` FROM `contest` WHERE `contest_id`=? AND `start_time`<=? AND `end_time`>?";
	$result=pdo_query($sql,$cid,$now,$now);
	$rows_cnt=count($result);
	if ($rows_cnt!=1){
		echo "You Can't Submit Now Because Your are not invited by the contest or the contest is not running!!";
		
		require_once("oj-footer.php");
		exit(0);
	}else{
		 $row=$result[0];
		$isprivate=intval($row[0]);
		
		if ($isprivate==1&&!isset($_SESSION['c'.$cid])){
			$sql="SELECT count(*) FROM `privilege` WHERE `user_id`=? AND `rightstr`=?";
			$result=pdo_query($sql,$user_id,"c$cid") ; 
			$row=$result[0];
			$ccnt=intval($row[0]);
			
			if ($ccnt==0&&!isset($_SESSION['administrator'])){
				$view_errors= "You are not invited!\n";
				require("template/".$OJ_TEMPLATE."/error.php");
				exit(0);
			}
		}
	}
	$sql="SELECT `problem_id` FROM `contest_problem` WHERE `contest_id`=? AND `num`=?";
	$result=pdo_query($sql,$cid,$pid);
	$rows_cnt=count($result);
	if ($rows_cnt!=1){
		$view_errors= "No Such Problem!\n";
		require("template/".$OJ_TEMPLATE."/error.php");
		
		exit(0);
	}else{
		 $row=$result[0];
		$id=intval($row['problem_id']);
		if($test_run) $id=-$id;
		
	}
}else{
       $id=0;
/*
	$view_errors= "No Such Problem!\n";
	require("template/".$OJ_TEMPLATE."/error.php");
	exit(0);
*/
       $test_run=true;
}
$language=intval($_POST['language']);
if ($language>count($language_name) || $language<0) $language=0;
$language=strval($language);


$source=$_POST['source'];
$input_text=$_POST['input_text'];
if(get_magic_quotes_gpc()){
	$source=stripslashes($source);
	$input_text=stripslashes($input_text);

}
$input_text=preg_replace ( "(\r\n)", "\n", $input_text );
$source=($source);
$input_text=($input_text);
$source_user=$source;
if($test_run) $id=-$id;
//use append Main code
$prepend_file="$OJ_DATA/$id/prepend.$language_ext[$language]";
if(isset($OJ_APPENDCODE)&&$OJ_APPENDCODE&&file_exists($prepend_file)){
     $source=file_get_contents($prepend_file)."\n".$source;
}
$append_file="$OJ_DATA/$id/append.$language_ext[$language]";
if(isset($OJ_APPENDCODE)&&$OJ_APPENDCODE&&file_exists($append_file)){
     $source.=("\n".file_get_contents($append_file));
}
//end of append 
if($language==6)
   $source="# coding=utf-8\n".$source;
if($test_run) $id=0;

$len=strlen($source);
//echo $source;




setcookie('lastlang',$language,time()+360000);

$ip=$_SERVER['REMOTE_ADDR'];


if($language==18){
$source=$tempfile;
$len=$_FILES["JarFile"]["size"];

if ($_FILES["JarFile"]["error"] > 0) {
	echo "Error: " . $_FILES["JarFile"]["error"] . "File size is too big, change in PHP.ini<br />";
} else if($_FILES["JarFile"]["size"] < 20000){
	$tempfile = $_FILES["JarFile"]["tmp_name"];
	echo "Upload: " . $_FILES["JarFile"]["name"] . "<br />";
	echo "Type: " . $_FILES["JarFile"]["type"] . "<br />";
	echo "Size: " . ($_FILES["JarFile"]["size"] / 1024) . " Kb<br />";
	//echo "Stored in: " . $tempfile . "<br />";
}

}else{
	if ($len<2){
		$view_errors="Code too short!<br>";
		require("template/".$OJ_TEMPLATE."/error.php");
		exit(0);
	}
	if ($len>65536){
		$view_errors="Code too long!<br>";
		require("template/".$OJ_TEMPLATE."/error.php");
		exit(0);
	}
}
// last submit
$now=strftime("%Y-%m-%d %X",time()-1);
$sql="SELECT `in_date` from `solution` where `user_id`=? and in_date>? order by `in_date` desc limit 1";
$res=pdo_query($sql,$user_id,$now);
if (count($res)==1){
	
		$view_errors="You should not submit more than twice in 10 seconds.....<br>";
		require("template/".$OJ_TEMPLATE."/error.php");
		exit(0);
	
}


if((~$OJ_LANGMASK)&(1<<$language)){

	if (!isset($pid)){
	$sql="INSERT INTO solution(problem_id,user_id,in_date,language,ip,code_length,result)
		VALUES(?,?,NOW(),?,?,?,14)";
		$insert_id= pdo_query($sql,$id,$user_id,$language,$ip,$len);
	}else{
	$sql="INSERT INTO solution(problem_id,user_id,in_date,language,ip,code_length,contest_id,num,result)
		VALUES(?,?,NOW(),?,?,?,?,?,14)";
		$insert_id= pdo_query($sql,$id,$user_id,$language,$ip,$len,$cid,$pid);
	}

if($language==18){//TTXS << << 
	var_dump($_FILES);
	$dest =  "/home/judge/jars/" . $insert_id . '.jar';
	//echo $dest . "<br />";
	if(move_uploaded_file($_FILES["JarFile"]["tmp_name"], $dest )){
		echo "OK!!" . "<br />";
	}else{
		echo "errcode" . $_FILES["JarFile"]["error"] . "<br />";
	}
	
	//echo "Stored in: " . "/home/judge/jars/" . $insert_id . '.jar' . "<br />";
}
	$sql="INSERT INTO `source_code_user`(`solution_id`,`source`)VALUES(?,?)";
	pdo_query($sql,$insert_id,$source_user);
	$sql="INSERT INTO `source_code`(`solution_id`,`source`)VALUES(?,?)";
	pdo_query($sql,$insert_id,$source_user);
	if($test_run){
		$sql="INSERT INTO `custominput`(`solution_id`,`input_text`)VALUES(?,?)";
		pdo_query($sql,$insert_id,$input_text);
	}
	$sql="update solution set result=0 where solution_id=?";
	pdo_query($sql,$insert_id);
	//using redis task queue
        if($OJ_REDIS){
           $redis = new Redis();
           $redis->connect($OJ_REDISSERVER, $OJ_REDISPORT);
           $redis->lpush($OJ_REDISQNAME,$insert_id);
        }

}


	 $statusURI=strstr($_SERVER['REQUEST_URI'],"submit",true)."status.php";
	 if (isset($cid)) 
	    $statusURI.="?cid=$cid";
	    
        $sid="";
        if (isset($_SESSION['user_id'])){
                $sid.=session_id().$_SERVER['REMOTE_ADDR'];
        }
        if (isset($_SERVER["REQUEST_URI"])){
                $sid.=$statusURI;
        }
   // echo $statusURI."<br>";
  
        $sid=md5($sid);
        $file = "cache/cache_$sid.html";
    //echo $file;  
    if($OJ_MEMCACHE){
		$mem = new Memcache;
                if($OJ_SAE)
                        $mem=memcache_init();
                else{
                        $mem->connect($OJ_MEMSERVER,  $OJ_MEMPORT);
                }
        $mem->delete($file,0);
    }
	else if(file_exists($file)) 
	     unlink($file);
    //echo $file;
    
  $statusURI="status.php?user_id=".$_SESSION['user_id'];
  if (isset($cid))
	    $statusURI.="&cid=$cid";
	 
   if(!$test_run){	
	header ("Location: $statusURI");
   }else{
   	if(isset($_GET['ajax'])){
                echo $insert_id;
        }else{
		?><script>window.parent.setTimeout("fresh_result('<?php echo $insert_id;?>')",1000);</script><?php
        }
   }
?>
