<?php

	if (session_status() === PHP_SESSION_NONE) {
    		session_start();
	}
	require_once "../common/dbconnect.php";
	require_once "../common/dbFetch.php";
	
	$menu = $_SESSION['menu'];
	$menupath = '../'.$menu.'/'.$menu.'Menu.php';

	$username = $_SESSION['username']; 
    $passphrase = $_SESSION['passphrase'];
	$first_initial = $_SESSION['first_initial']; 
	
	$currentPassphrase_label = 'Current Passphrase';
	$newpassphrase_label = 'New Passphrase';
	$cpassphrase_label = 'Confirm Passphrase';
	
	$currentPassphrase = '';
	$newpassphrase = '';
	$cpassphrase = '';
	$cmessage = '';

	$row = NULL;
    $query = 'SELECT *  FROM loginInfo WHERE username = ? and pwdHash = ?';
	$array = array($username, $passphrase);
	$row = fetchArray($con, $query, $array);

	$currentPassphraseDB = $row[0]['pwdHash'];
    $id = $row[0]['id'];


	if(isset($_POST['submit'])){
		if(isset($_POST['currentPassphrase'])){
		
			$currentPassphrase = $_POST['currentPassphrase'];

		}

		if(isset($_POST['newpassphrase'])){
		
			$newpassphrase = $_POST['newpassphrase'];

		}
		if(isset($_POST['cpassphrase'])){
		
			$cpassphrase = $_POST['cpassphrase'];
		
		}
		

		if ($currentPassphrase != $currentPassphraseDB){
			$cmessage = 'Current passphrase wrong.';
			
		}


		elseif ($newpassphrase != $cpassphrase){
			$newpassphrase_label = '<font color = "red">New Passphrase</font>';
			$cpassphrase_label = '<font color = "red">Confirm Passphrase</font>';
			$cmessage = "Passwords not matching.";
			
		}
		
		else {
			$stmt = $con->prepare('UPDATE loginInfo SET pwdHash= ? WHERE id = ?');
			$stmt->execute(array($newpassphrase, $id));
			$_SESSION['passphrase'] = $newpassphrase;
			header("Location: ".$menupath);	
		}
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
		<title>Change Password</title>
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
        				<a href="#" class = "inactiveLink">Change Password</a>
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
			
			<form action="changePassword.php" method="post">
				<div class="rvt-box__row">
					<label for="currentPassphrase"><?php print $currentPassphrase_label;?></label><br>
					<input id="currentPassphrase" name="currentPassphrase" type="password" value="<?php print $currentPassphrase; ?>" size="25" required>
				</div>
				<div class="rvt-box__row">
					<label for="newpassphrase"><?php print $newpassphrase_label;?></label><br>
					<input id="newpassphrase" name="newpassphrase" type="password" value="<?php print $newpassphrase; ?>" size="25" required>
				</div>
				<div class="rvt-box__row">
					<label for="cpassphrase"><?php print $cpassphrase_label;?></label><br>
					<input id="cpassphrase" name="cpassphrase" type="password" value="<?php print $cpassphrase; ?>" size="25" required>
				</div>	
				<div class="rvt-box__row">
						<?php print "<h2>".$cmessage."</h2>"; ?>
				</div>
				<div class="rvt-box__row rvt-button-group">
					<input id="submit" name="submit" class="rvt-button rvt-button--full-width " type="submit" value = "Confirm">
					<a class="rvt-button rvt-button--secondary rvt-button--full-width " href = "<?php echo $menupath ?>">Cancel</a>
				</div>
			</form>	
			
		</div>
	</body>
</html>	