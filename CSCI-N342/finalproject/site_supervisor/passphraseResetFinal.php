<?php
	if (session_status() === PHP_SESSION_NONE) {
		session_start();
	};
	require_once "../common/dbconnect.php";
	include "../common/dbFetch.php";
	$loginInfoId = $_SESSION['loginInfoId'];

	$passphrase_label = 'New Passphrase';
	$cpassphrase_label = 'Confirm Passphrase';
	$passphrase = '';
	$cpassphrase = '';
	$cmessage = 'Enter above details to change password. Make sure';
	if(isset($_POST['submit'])){

		if(isset($_POST['passphrase'])){
		
			$passphrase = $_POST['passphrase'];

		}
		if(isset($_POST['cpassphrase'])){
		
			$cpassphrase = $_POST['cpassphrase'];
		
		}
		
		if($passphrase != $cpassphrase){
			$passphrase_label = '<font color = "red">Passphrase</font>';
			$cpassphrase_label = '<font color = "red">Confirm Passphrase</font>';
			$cmessage = "Passwords don't match.";
	
		}
		
		else if($passphrase != ''){
			echo $passphrase, $loginInfoId;
		
			$stmt = $con->prepare('UPDATE loginInfo SET pwdHash= ? WHERE id = ?');
			$stmt->execute(array($passphrase, $loginInfoId));
			header("Location: .././");
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
		<title>Reset Password</title>
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
        				<a href="#" class = "inactiveLink">Reset Password</a>
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
			
			<form action="passphraseResetFinal.php" method="post">
				<div class="rvt-box__row">
					<label for="passphrase"><?php print $passphrase_label;?></label><br>
					<input id="passphrase" name="passphrase" type="password" value="<?php print $passphrase; ?>" size="25" required>
				</div>
				<div class="rvt-box__row">
					<label for="cpassphrase"><?php print $cpassphrase_label;?></label><br>
					<input id="cpassphrase" name="cpassphrase" type="password" value="<?php print $cpassphrase; ?>" size="25" required>
				</div>

				<div class="rvt-box__row">
					<?php print "<h2>".$cmessage."</h2>"; ?>
				</div>

				<div class="rvt-box__row rvt-button-group">
					<button class="rvt-button rvt-button--full-width" id="submit" name="submit" type="submit">Reset Password</button>
					<a class="rvt-button rvt-button--secondary rvt-button--full-width" href = "../index.php">Cancel</a>
				</div>
				
			</form>			
		</div>
<?php include "../common/footer.php" ?>
