<html>
<head>
    <title>SQL Injection</title>
</head>
<body>
    <form action="2.php" method="post">
        Enter the id:&nbsp;<input type=text  name="user"><br>
        <input type="submit" value="Submit">
    </form>
    
    <?php
    if ($_SERVER["REQUEST_METHOD"] == "POST") 
    {
        $servername="localhost";
	$username="root";
	$password="manaswini";
	$dbname="manas";
	
	$conn =new mysqli($servername, $username, $password,$dbname);
	
	if($conn->connect_error)
	{
		echo "connection failed\n";
	}

 
        $user = $_POST["user"];
        echo $user."<br>";
        $sql = "SELECT * FROM det where username = " .$user;
        
        if ($conn->multi_query($sql)) 
        {
            echo "Login Successful";
        } 
        else 
        {
            echo "Failed Login";
        }
    }
    ?>
</body>
</html>
