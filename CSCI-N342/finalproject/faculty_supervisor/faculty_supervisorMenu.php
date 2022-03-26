<?php 

if (session_status() === PHP_SESSION_NONE) {
    session_start();
};

$_SESSION['menu'] = 'faculty_supervisor';

$username = "";
$first_initial = "";

$username = $_SESSION['username'];
$first_initial = $_SESSION['first_initial']; ?>
<!DOCTYPE html>
<html lang="en-US">
<head>
    <meta charset="utf-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link media="all" rel="stylesheet" href="../iudesign/css/rivet.min.css">
    <script src="../iudesign/js/rivet.min.js"></script>
    <!-- Change Title here for each module !-->
    <title>Faculty Supervisor Menu</title>
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
        <a href="#" class = "inactiveLink">Faculty Supervisor Menu</a>
    </span>
    <!-- Wrapper for header interactive elements -->
    <div class="rvt-header__controls">
        <!-- Main inline nav element -->
        <nav class="rvt-header__main-nav" role="navigation">
            <ul>
                <li>
                    <a href="faculty_supervisorMenu.php" aria-current="page">Dashboard</a>
                </li>
                <!-- First Navigation !-->
                <li>
                    <a href="reviewApps.php">Review Applications</a>
                </li>   
                <!-- Drop down Navigation !-->
                <li>
                    <div class="rvt-dropdown">
                        <button type="button" class="rvt-dropdown__toggle" data-dropdown-toggle="dropdown-1" aria-haspopup="true" aria-expanded="false">
                            <span class="rvt-dropdown__toggle-text">Account Settings</span>
                            <svg aria-hidden="true" xmlns="http://www.w3.org/2000/svg" width="16" height="16" viewBox="0 0 16 16">
                                <title>Dropdown icon</title>
                                <path fill="currentColor" d="M8,12.46a2,2,0,0,1-1.52-.7L1.24,5.65a1,1,0,1,1,1.52-1.3L8,10.46l5.24-6.11a1,1,0,0,1,1.52,1.3L9.52,11.76A2,2,0,0,1,8,12.46Z"
                                />
                            </svg>
                        </button>
                        <div class="rvt-dropdown__menu" id="dropdown-1" aria-hidden="true">
                            <a href="../common/editProfile.php">Edit Profile</a>
                            <a href="../common/changePassword.php">Change Password</a>
                        </div>
                    </div>
                </li>            
            </ul>
            
                
        </nav>
        <!-- ID menu w/ dropdown -->
        <div class="rvt-header-id">
            <div href="#0" class="rvt-header-id__profile">

                <!-- change these to your username for now !-->
                <span class="rvt-header-id__avatar" aria-hidden="true"><?php print $first_initial ?></span>
                <span class="rvt-header-id__user"><?php print $username ?></span>
            </div>
            <a href="../common/logout.php" class="rvt-header-id__log-out">Log out</a>
        </div>
    </div>
     
</header>
    <main role="main" id="main-content">

        <!-- **************************************************************
            Start building here!
        *************************************************************** -->

<?php include "../common/footer.php" ?>
