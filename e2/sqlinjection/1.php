<html>
<body>
	<form method=post action=1.php>
	Username : <input type=text name=user value="3555" /><br>
	Password : <input type=text name=pass value="man" /><br>
	
	<input type=submit name=submit value="submit" /><br>
	</form>


<?php

if($_SERVER["REQUEST_METHOD"]=="POST")
{
	//echo "hi";
	$servername="localhost";
	$username="root";
	$password="manaswini";
	$dbname="manas";
	
	$conn =new mysqli($servername, $username, $password,$dbname);
	
	if($conn->connect_error)
	{
		echo "connection failed\n";
	}
	
	$user=$_POST["user"];
	$pass=$_POST["pass"];

	echo $user."<br>".$pass."<br>";
	
//	$sql = "select * from details where username=".$user;

        $sql="select * from details where username='$user' and password='$pass'";
	$result=$conn->query($sql);
	

	if($result->num_rows > 0)
	{
		while($row = $result->fetch_assoc())
		{
			echo $row["username"]." ".$row["password"]." ".$row["info"]."<br>";
		}
		echo "<br>done";
	}
	else
	{
		echo "<br>invalid";
	}	
}

?>

</body>
</html>
