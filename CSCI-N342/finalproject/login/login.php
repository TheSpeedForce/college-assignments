<!-- git add . && git commit -m "16-nov-21" && git push origin Pawas !-->
<?php

if (session_status() === PHP_SESSION_NONE) {
	session_start();
};

	require_once "../common/dbconnect.php";
	include "../common/dbFetch.php";
	
	$username = '';
	$password = '';
	$first_initial = '';
	$validity = '';

	$username_label='Username';
	$passphrase_label='Passphrase';
	if(isset($_POST['username'])){
		
		$username = $_POST['username'];
			
	}
	if(isset($_POST['passphrase'])){
		
		$passphrase = $_POST['passphrase'];
	
	}
	
	if($username != '' && $passphrase != ''){

		
		//$sql = 'select * from loginInfo where username = ' .$username. ' and pwdHash = ' .$passphrase;
		//print $sql;
		$row = NULL;
		$query = 'SELECT *  FROM loginInfo WHERE username = ? and pwdHash = ?';
		$array = array($username, $passphrase);
		$row = fetchArray($con, $query, $array);
		
		
		if($row == NULL){
			$validity = "Invalid Credentials try again";
			$username_label='<font color="red">Username</font>';
			$passphrase_label='<font color="red">Passphrase</font>';
		}
		else{
			$first_initial = strtoupper(substr($username, 0, 1));

			$_SESSION['userId'] = $row[0]['id'];
			$_SESSION['username'] = $username;
			$_SESSION['passphrase'] = $passphrase;
			
			$_SESSION['email'] = $row[0]['email'];
			$_SESSION['fName'] = $row[0]['fName'];
			$_SESSION['lName'] = $row[0]['lName'];
			$_SESSION['first_initial'] = $first_initial;

			$datetime = date('Y-m-d h:i:sa');
			//echo($datetime);
			
            $row = $row[0];
            //echo($row['id']);
			if($row['firstLogin'] == NULL){
				$query = 'UPDATE loginInfo SET firstLogin = ? WHERE id = ?';
				$array = array($datetime, $row['id']);
				$stmt = $con->prepare($query);
				$stmt->execute($array);
			}
            
			$query = 'UPDATE loginInfo SET lastLogin = ? WHERE id = ?';
			$array = array($datetime, $row['id']);
			$stmt = $con->prepare($query);
			$stmt->execute($array);
			
			$checkRow = NULL;
			$query = 'SELECT * FROM student WHERE loginInfoId = ?';
			$array = array($row['id']);
			$checkRow = fetchArray($con, $query, $array);
			//var_dump($checkRow);
			if($checkRow == NULL){
				//echo("student IS NULL");
				$query = 'SELECT * FROM admin WHERE loginInfoId = ?';
				$checkRow = fetchArray($con, $query, $array);
				//var_dump($checkRow);
				if($checkRow == NULL){
					//echo("admin IS NULL");
					$query = 'SELECT * FROM supervisor WHERE loginInfoID = ?';
					$checkRow = fetchArray($con, $query, $array);
					//var_dump($checkRow);
					if($checkRow == NULL){
						//echo('There is a problem');
					}else{
						//echo('supervisor NOT NULL');
						
						if($checkRow[0]['roleId'] == 1){
							header("Location: ../site_supervisor/site_supervisorMenu.php");
						}elseif($checkRow[0]['roleId'] == 2){
							header("Location: ../faculty_supervisor/faculty_supervisorMenu.php");
						}
					}
				}
				else{
					//echo('admin NOT NULL!');
					header("Location: ../admin/adminMenu.php");
				}
			}
			else{
				//echo('student NOT NULL!');
				header("Location: ../student/studentMenu.php");
			}

            
            
		}
		
	
	}
	else{
		$validity = "Username or Password can't be empty";
	}

?>

<!DOCTYPE html>
	<html lang="en-US">
	<head>
	 	<meta charset="utf-8">
	    	<meta http-equiv="X-UA-Compatible" content="IE=edge">
	    	<meta name="viewport" content="width=device-width, initial-scale=1.0">
	    	<link media="all" rel="stylesheet" href="../iudesign/css/rivet.min.css">
	    	<script src="../iudesign/js/rivet.min.js"></script>
	    	<!-- Change Title here for each module !-->
		<title>IU Login</title>
	</head>	
	<body>
		<header class="rvt-header" role="banner">
    			<a class="rvt-skip-link" href="#main-content">Skip to content</a>
    			<!-- Trident -->
    			<div class="rvt-header__trident">
        				<svg class="rvt-header__trident-logo" xmlns="http://www.w3.org/2000/svg" viewBox="0 0 41 48" aria-hidden="true">
           			 	<title id="iu-logo">Indiana University Logo</title>
            				<rect width="41" height="48" fill="#900"/>
            				<polygon points="24.59 12.64 24.59 14.98 26.34 14.98 26.34 27.78 22.84 27.78 22.84 10.9 24.59 10.9 24.59 8.57 16.41 8.57 16.41 10.9 18.16 10.9 18.16 27.78 14.66 27.78 14.66 14.98 16.41 14.98 16.41 12.64 8.22 12.64 8.22 14.98 9.97 14.98 9.97 30.03 12.77 33.02 18.16 33.02 18.16 36.52 16.41 36.52 16.41 39.43 24.59 39.43 24.59 36.52 22.84 36.52 22.84 33.02 28 33.02 31.01 30.03 31.01 14.98 32.78 14.98 32.78 12.64 24.59 12.64" fill="#fff"/>
        				</svg>
    			</div>
    			<!-- App title -->
    			<span class="rvt-header__title">
        				<a href="#" class = "inactiveLink">IU Login</a>
    			</span>
    			<!-- Wrapper for header interactive elements -->
    			<div class="rvt-header__controls">
       			<!-- Main inline nav element -->
        			<nav class="rvt-header__main-nav" role="navigation">
                    			</nav>
        			<!-- ID menu w/ dropdown -->
        			<div class="rvt-header-id">
                			</div>
		</header>
		<div class="rvt-box__body">
			
			<form action="login.php" method="post">
				<div class="rvt-box__row">
					<label for="username"><?php print $username_label;?></label><br>
					<input type="text" id="username" name="username" type="text" value="<?php print $username; ?>" size="25">
				</div>
				<div class="rvt-box__row">
					<label for="password"><?php print $passphrase_label;?></label><br>
					<input class="signin__field signin__field--pass required" id="passphrase" name="passphrase" type="password" value="" autocorrect="off" autocomplete="off" size="25" >
					<small id="validity" class="rvt-display-block rvt-m-bottom-md"><?php print $validity ?></small>
				</div>
				<div class="rvt-box__row rvt-button-group">
					<button class="rvt-button" type="submit" >&nbsp&nbsp&nbspLog In&nbsp&nbsp&nbsp</button>
					<a class="rvt-button rvt-button--secondary" href = "../index.php" >&nbsp&nbsp&nbspCancel&nbsp&nbsp&nbsp</a>
				</div>
				<div class="rvt-box__row">
					<a id="reset_passphrase" href=".\siteSupervisorLogin.php">Site Supervisor? Click Here!</a>
				</div>
				<div class="rvt-box__row">
					<a id="reset_passphrase" href=".\passresetemail.php">Forgot Passphrase?</a>
				</div>
			</form>
			
		</div>
<?php include "../common/footer.php" ?>
