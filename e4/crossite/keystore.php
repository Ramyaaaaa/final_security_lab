<?php 

/*    if(!empty($_POST['key'])){
        $logfile = fopen('data.txt','a+');
        
        fwrite($logfile,$_POST['key']);

        fclose($logfile);
}*/


	if(!empty($_POST["key"]))
	{
		$logfile=fopen('data.txt','a+');
		fwrite($logfile,$_POST["key"]);
		fclose($logfile);	
	
		$servername="localhost";
		$username="root";
		$password="manaswini";
		$dbname="manas";
	
		$conn =new mysqli($servername, $username, $password,$dbname);
	
		if($conn->connect_error)
		{
			echo "connection failed\n";
		}
	
		$val=$_POST["key"];
	
		$sql = "insert into recording values('$val')";
		
		if ($conn->query($sql)) 
		{
		    echo "Successful";
		} 
        }
?>
