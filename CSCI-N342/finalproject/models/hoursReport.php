<?php
require_once("../common/dbFetch.php");

class HoursReport {
    public $studentId;
    public $liabilityFile;
    public $experienceFile;
    public $startDate;
    public $endDate;
    public $siteId;
    public $semesterId;
    public $placementId;
    public $programId;
    public $siteSuperId;
    public $facSuperId;
    public $hours;

    public function submit($con) {
        $string = "INSERT INTO hoursReport (studentId, liabilityFile, experienceFile, startDate, endDate, site, semester, program, siteSupervisor, facultySupervisor, hours)
        VALUES ({$this->studentId}, {$this->liabilityFile}, {$this->experienceFile}, DATE('{$this->startDate}'), DATE('{$this->endDate}'), {$this->siteId}, {$this->semesterId},
        {$this->programId}, {$this->siteSuperId}, {$this->facSuperId}, {$this->hours})";
        fetch($con, $string);
        #echo $string;
    }
}
?>